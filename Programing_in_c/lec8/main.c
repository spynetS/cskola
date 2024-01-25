#include "totavg.h"
#include <stdio.h>


int main(){
  int amount;
  scanf("%d",&amount);
  double arr[amount];
  for(int i = 0; i < amount; i++){
    scanf("%lf",&arr[i]);
  }
  printf("total %.1lf\naverage %.1lf\n",total(arr,amount),average(arr,amount));

  return 0;
}
