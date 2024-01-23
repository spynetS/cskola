// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){

  int amounts;
  while(scanf("%d",&amounts)>0){
    printf("%d elements:",amounts);
    for(int i = 0; i < amounts; i++){
      int temp;
      scanf("%d",&temp);
      printf(" %d",temp);
    }
    printf("\n");
    amounts=0;
  }


  return 0;
}
