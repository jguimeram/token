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
#include <string.h>
#include <ctype.h>

#define MAX_CAPACITY 20

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

    /* 
    printf("%ld\n", sizeof(*exp)); //print the size of one token + padding
    printf("size of p: %ld\n", sizeof(p)); //8 bytes:
    printf("size of *p: %ld\n", sizeof(*p)); //1 byte (char)
*/
    int i = 0;

    while(*p){
          //   printf("index %d\n", i); why runs 15 times?
             if(isdigit(*p)){
                Token t;
                t.value = strtol(p, &end, 10);  
                t.type = TOK_NUM;
                //printf("partial sum: %ld\n", t.value);
                //printf("type: %d\n", t.type);
                exp[i] = t;
                p = end;
              }else if(*p == '+'){
                Token t;
                t.value = 0;
                t.type = TOK_ADD;
                exp[i] = t;
              }else if(*p == '-'){
                Token t;
                t.value = 0;
                t.type = TOK_SUB;
                exp[i] = t;
             }
       p++;
       i++;
    }

   printf("Printing array of struct...:\n"); 
   for(int i = 0; i < MAX_CAPACITY; i++){

    printf("%d %ld\n", exp[i].type, exp[i].value);
   }

    return 0;
}
