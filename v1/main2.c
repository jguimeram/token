/*
 * =====================================================================================
 *
 *       Filename:  main2.c
 *
 *    Description: Improved calculator with token-based parsing
 *
 *        Version:  2.0
 *        Created:  09/07/2025
 *       Compiler:  gcc
 *
 * =====================================================================================
*/ 
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define MAX_ERROR_MSG 100

typedef enum {
    TOK_NUM,
    TOK_ADD,
    TOK_SUB,
    TOK_INV,
} TokType;

typedef struct {
    TokType type;
    long value;
} Token;

typedef struct {
    Token* tokens;
    size_t size;
    size_t capacity;
} TokenArray;

// Function prototypes
TokenArray* create_token_array(size_t initial_capacity);
void free_token_array(TokenArray* arr);
int add_token(TokenArray* arr, Token token);
int resize_token_array(TokenArray* arr);
int tokenize_expression(const char* expr, TokenArray* tokens, char* error_msg);
long evaluate_expression(TokenArray* tokens, char* error_msg);

// Create a new dynamic token array
TokenArray* create_token_array(size_t initial_capacity) {
    TokenArray* arr = malloc(sizeof(TokenArray));
    if (!arr) return NULL;

    arr->tokens = malloc(sizeof(Token) * initial_capacity);
    if (!arr->tokens) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

// Free the token array
void free_token_array(TokenArray* arr) {
    if (arr) {
        free(arr->tokens);
        free(arr);
    }
}

// Add a token to the array, resize if necessary
int add_token(TokenArray* arr, Token token) {
    if (arr->size >= arr->capacity) {
        if (!resize_token_array(arr)) {
            return 0;
        }
    }
    arr->tokens[arr->size++] = token;
    return 1;
}

// Resize the token array
int resize_token_array(TokenArray* arr) {
    size_t new_capacity = arr->capacity * 2;
    Token* new_tokens = realloc(arr->tokens, sizeof(Token) * new_capacity);
    if (!new_tokens) return 0;
    
    arr->tokens = new_tokens;
    arr->capacity = new_capacity;
    return 1;
}

// Tokenize the input expression
int tokenize_expression(const char* expr, TokenArray* tokens, char* error_msg) {
    const char* p = expr;
    char* end;

    while (*p) {
        // Skip whitespace
        while (isspace(*p)) p++;
        if (!*p) break;

        Token t;
        if (isdigit(*p)) {
            t.value = strtol(p, &end, 10);
            t.type = TOK_NUM;
            p = end;
        } else if (*p == '+') {
            t.type = TOK_ADD;
            t.value = 0;
            p++;
        } else if (*p == '-') {
            t.type = TOK_SUB;
            t.value = 0;
            p++;
        } else {
            snprintf(error_msg, MAX_ERROR_MSG, "Invalid character: %c", *p);
            return 0;
        }

        if (!add_token(tokens, t)) {
            strcpy(error_msg, "Failed to add token: memory allocation error");
            return 0;
        }
    }
    return 1;
}

// Evaluate the tokenized expression
long evaluate_expression(TokenArray* tokens, char* error_msg) {
    if (tokens->size == 0) {
        strcpy(error_msg, "Empty expression");
        return 0;
    }

    long result = 0;
    size_t i = 0;

    // First token must be a number
    if (tokens->tokens[0].type != TOK_NUM) {
        strcpy(error_msg, "Expression must start with a number");
        return 0;
    }

    while (i < tokens->size) {
        if (tokens->tokens[i].type == TOK_NUM) {
            result = tokens->tokens[i].value;
            i++;
        } else {
            // Check if we have a number after the operator
            if (i + 1 >= tokens->size || tokens->tokens[i + 1].type != TOK_NUM) {
                strcpy(error_msg, "Expected number after operator");
                return 0;
            }

            if (tokens->tokens[i].type == TOK_ADD) {
                result += tokens->tokens[i + 1].value;
            } else if (tokens->tokens[i].type == TOK_SUB) {
                result -= tokens->tokens[i + 1].value;
            }
            i += 2;
        }
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        printf("Example: %s \"5 + 3 - 2\"\n", argv[0]);
        return 1;
    }

    char error_msg[MAX_ERROR_MSG] = {0};
    TokenArray* tokens = create_token_array(INITIAL_CAPACITY);
    
    if (!tokens) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Tokenize the expression
    if (!tokenize_expression(argv[1], tokens, error_msg)) {
        printf("Error during tokenization: %s\n", error_msg);
        free_token_array(tokens);
        return 1;
    }

    // Evaluate the expression
    long result = evaluate_expression(tokens, error_msg);
    if (error_msg[0] != '\0') {
        printf("Error during evaluation: %s\n", error_msg);
        free_token_array(tokens);
        return 1;
    }

    printf("Result: %ld\n", result);
    free_token_array(tokens);
    return 0;
}
