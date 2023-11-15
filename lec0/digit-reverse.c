// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse(const char* src, char* dst){
  size_t len = strlen(src);
  int index = 0;
  for(int i = len-1; i >= 0;i--){
    dst[index] = src[i];
    index++;
  }
  dst[index]='\0';
}

int main(){
  char input[11];
  while(scanf("%s",input)>0){
    char reversed[11];
    reverse(input, reversed);
    int i = atoi(reversed);
    printf("%d\n", i);
  }
  return 0;
}
