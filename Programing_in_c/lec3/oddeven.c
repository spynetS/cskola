// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){
  int value;
  while(scanf("%d",&value)==1){
    if(value %2 == 0) printf("even\n");
    else printf("odd\n");
  }
  return 0;
}
