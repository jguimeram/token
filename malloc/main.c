/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2025 12:32:25 PM
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

int main(){
    
  char *buffer;
  int capacity = 1024;

  buffer = (char *)malloc(capacity);

  printf("%ld", sizeof(*buffer));

  return 0;
}
