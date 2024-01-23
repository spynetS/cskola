// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){

  int amounts;
  int values[100];
  while(scanf("%d",&amounts)>0){
    for(int i = 0; i < amounts; i++){
      int temp;
      scanf("%d",&temp);
      values[i]=temp;
    }
    int index;
    scanf("%d",&index);
    printf("%d\n",values[index]);
    amounts=0;
  }


  return 0;
}
