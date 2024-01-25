// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char value[60];
  while(scanf("%s",value)>0){
    size_t size = strlen(value);
    char prev = '\0';

    char buffer[60];
    size_t count = 0;
    for(size_t i = 0 ; i < size; i ++){
      if(value[i]!=prev){
        buffer[count] = value[i];
        count++;
      }
      prev=value[i];
    }
    printf("%s\n",buffer);
    memset(buffer,'\0',60);

  }
  return 0;
}
