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

typedef enum{
  TOK_NUM,
  TOK_ADD,
  TOK_SUB,
  TOK_INV,
}TokType;


typedef struct{
  char *type;
  long value;
}Token;

int main(int argc, char **argv){

    if(argc < 2){
      printf("[ERROR]: Usage: %s + expression (i.e: 3+2)\n", argv[0]);
      return 1;
    }
  
    const char *p = argv[1];
    char *end;
    printf("size of p: %ld\n", sizeof(p)); //8 bytes
    printf("size of *p: %ld\n", sizeof(*p)); //1 byte (char)

    long int sum = 0;

    while(*p){
      if(isdigit(*p)){
        sum = strtol(p, &end, 10);  
        printf("partial sum: %ld\n", sum);
        p = end;
      }
      p++;
    }
  
  //printf("sum: %ld\n", sum);

    
    return 0;
}
