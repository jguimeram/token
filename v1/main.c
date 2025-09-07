/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: calculate by tokens 
 *
 *        Version:  1.0
 *        Created:  08/26/2025 10:44:46 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
*/ 
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_CAPACITY 5 

typedef enum{
  TOK_NUM,
  TOK_ADD,
  TOK_SUB,
  TOK_INV,
}TokType;


typedef struct{
  TokType type;
  long value;
}Token;




int main(int argc, char **argv){

    if(argc < 2){
      printf("[ERROR]: Usage: %s + expression (i.e: 3+2)\n", argv[0]);
      return 1;
    }
  
    const char *p = argv[1];
    char *end;
     
    Token *exp = (Token *)malloc(sizeof(Token)*MAX_CAPACITY);

    int len = 0;

    while(*p)
        {
            if(len == MAX_CAPACITY){
            printf("[ERROR:] not  enough memory. Buy more RAM");
            return -1;
            }


            Token t;
             if(isdigit(*p)){
                t.value = strtol(p, &end, 10);  
                t.type = TOK_NUM;
                p = end;
              }else if(*p == '+'){
                t.value = 0;
                t.type = TOK_ADD;
                p++;
              }else if(*p == '-'){
                t.value = 0;
                t.type = TOK_SUB;
                p++;
             }
             exp[len++] = t; //Post-increment (i++) → returns the current value of i, then increments i afterwards.
    }

  
  long res = 0;  

  for(int i = 0; i < len; i++){
    printf("current i value: %d\n", i);
    if(exp[i].type == TOK_NUM){
        res = exp[i].value; 
    }else if (exp[i].type == TOK_ADD) {
       res = res + exp[++i].value; 
    }else if (exp[i].type == TOK_SUB){
    res = res - exp[++i].value; 
    }
  }

    printf("res: %ld", res);

    free(exp);
    return 0;
}
