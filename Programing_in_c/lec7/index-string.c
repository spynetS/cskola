// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char string[60];
  int value;
  while(scanf("%s %d",string,&value)>0){
    printf("%c\n",string[value]);
    memset(string,'\0',60);
  }
  return 0;
}
