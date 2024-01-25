// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y){

    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int main(){
  int a,b;
  while(scanf("%d %d",&a,&b)>0){
    printf("%d\n",gcd(a,b));
  }
  return 0;
}
