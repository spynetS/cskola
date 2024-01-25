// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char word[60];
  int value;
  char replace;
  while(scanf("%s %d %c",word,&value,&replace)>0){
    word[value]=replace;
    printf("%s\n",word);
    memset(word,'\0',60);
  }
  return 0;
}
