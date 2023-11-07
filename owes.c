// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){
  double value;
  char name1[30];
  char name2[30];
  while(scanf("%lf %s %s",&value,name1,name2)>0){
    printf("%s owes $%.2lf dollars to %s.\n",name1,value,name2);
  }
  return 0;
}
