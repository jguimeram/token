/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2025 04:02:48 PM
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

int main(int argc, char **argv){
 
  if(argc < 2){
   fprintf(stderr, "not enough arguments\n");
   return -1;
  }

  char *filename = argv[1];

  FILE *f = fopen(argv[1], "rb");
 
  printf("%p\n", *f);

  if(f == NULL){
  perror("fopen"); 
  return 1;
  } 
  
  if(fseek(f, 0, SEEK_END != 0)){
  perror("fseek");    
  fclose(f);
  return 1;
  }


  long size =  ftell(f);
  printf("size: %ld\n", size);

  if(size < 0){
  perror("ftell");
  fclose(f);
  return 1;  
  }

  rewind(f);

  char *buffer = malloc(size + 1);

  if(!buffer){
   perror("malloc");
   fclose(f);
   return 1;
  }

  size_t read = fread(buffer, 1, size, f);
  buffer[read] = '\0';


  printf("Content: %s\n", buffer);

  free(buffer);
  fclose(f);
  return 0;
}

