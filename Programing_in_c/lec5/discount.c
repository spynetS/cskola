// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char person[30];
  int age;
  while(scanf("%s %d",person,&age)>0){
    char result[11];

    if(age < 18) strcpy(result,"discount");
    else if(strcmp(person,"student") == 0 && age <= 25) strcpy(result,"discount");
    else if(age >= 65) strcpy(result,"discount");
    else strcpy(result,"full price");

    printf("%s\n",result);
  }
  return 0;
}
