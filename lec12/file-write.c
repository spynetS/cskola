// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>


int main(){

  FILE *f;

  f = fopen("message.txt","w");
  fprintf(f,"Hello file system.\n");
  fclose(f);
  printf("Created text file message.txt\n");

  return 0;
}
