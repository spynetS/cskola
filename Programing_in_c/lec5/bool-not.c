// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char value[6];
  while(scanf("%s",value)>0){
    if(strcmp(value,"true")==0) printf("false\n");
    else printf("true\n");
  }
  return 0;
}
