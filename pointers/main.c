/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2025 04:42:49 PM
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

void function_pointer(int *num, char *name){
      printf("num: %d\n", *num);
      printf("char: %s\n", name);
}


int main(){
  printf("Hello, pointers\n");
  int a = 15;
  int *p = &a;
  printf("%d\n", *p);
  printf("%p\n", p);

  char *name = "nunca mas";

  printf("%s\n", name);
  printf("%c\n", *name); //prints the first position of name. *name and name[0] are equal
  printf("%p\n", name);

  function_pointer(p, name);

  return 0;
}

