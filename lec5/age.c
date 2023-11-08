// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){
  char name[30];
  int age;
  while(scanf("%s %d",name,&age)>0){
    printf("%s is %d years old.\n",name,age);
  }
  return 0;
}
