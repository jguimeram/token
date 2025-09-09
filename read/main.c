/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/2025 03:02:22 PM
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
  if (argc < 2){
    fprintf(stderr, "Usage: %s file\n", argv[0]);
    return 1;
  }
  
  const char *filename = argv[1];
 

  FILE *fp = fopen(filename, "rb");

  if(!fp){
    perror("fopen");
    return -1;
  }

  fseek(fp, 0,SEEK_END);

  long fsize = ftell(fp);

  printf("%ld\n", fsize);

  rewind(fp);

  char *str = malloc(fsize + 1);

  printf("size of str: %ld\n", sizeof(str));

  fread(str, fsize, 1, fp);

  /* str manipulation */
 
  char *ptr = &str[0];

  int i = 0;

  while(*ptr){
    printf("%c", str[i]);
    ptr++;
    i++;
  }


/*    for(size_t i = 0; i < (size_t)fsize ; ++i){
    printf("%c", str[i]);
  } */  

  /*  */

  fclose(fp);

  free(str);

  return 0;
}

