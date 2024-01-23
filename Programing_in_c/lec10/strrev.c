// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strreverse(const char *s){

  char *new = (char*)malloc(sizeof(char*)*strlen(s));
  int index = 0;
  for(int i = strlen(s)-1; i >= 0; i--){
    new[index] = s[i];
    index++;
  }
  new[index] = '\0';
  return new;
}
int main(){
  char buffer[60];
  while(scanf("%s",buffer)>0){
    char *val = strreverse(buffer);
    printf("The reverse of \"%s\" is \"%s\".\n",buffer,val);
    free(val);
  }

  return 0;
}
