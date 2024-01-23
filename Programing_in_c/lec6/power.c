// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int power(int b, int n){
  return pow(b,n);
}
int main(){
  int a,b;
  while(scanf("%d%d",&a,&b)>0){
    printf("%d\n",power(a,b));
  }
  return 0;
}
