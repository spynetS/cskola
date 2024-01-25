// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>


int main(){
  int amount;
  scanf("%d",&amount);

  for(int i = amount;i > 0;i--){
    printf("%d\n",i);
  }
  printf("Go!\n");

  return 0;
}
