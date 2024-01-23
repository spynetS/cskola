// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define bool int

bool and (bool i1, bool i2){
  return i1 == TRUE && i1==i2;
}
bool or (bool i1, bool i2){
  return i1 == TRUE ? i1 : i2;
}

int main(){
  char value1[6];
  char and_or[4];
  char value2[6];
  while(scanf("%s %s %s",value1,and_or,value2)>0){
    int result = 0;
    int v1 = strcmp(value1,"true")==0?TRUE:FALSE;
    int v2 = strcmp(value2,"true")==0?TRUE:FALSE;

    if(strcmp(and_or,"and")==0) result = and(v1,v2);
    else result = or(v1,v2);

    printf("%s\n",result==TRUE?"true":"false");

  }
  return 0;
}
