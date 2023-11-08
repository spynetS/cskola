// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>


int main(){
  int amount;
  scanf("%d",&amount);
  int sum = 0;
  for(int i = 0; i < amount;i ++){
    int temp;
    scanf("%d",&temp);
    sum+=temp;
  }
  printf("%d\n",sum);
  return 0;
}
