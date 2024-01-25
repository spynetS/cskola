//2023 Alfred Roos
#include <stdio.h>

int gcd(int x, int y){

    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}

int main(){
  int a,b;
  while(scanf("%d %d",&a,&b)>0){
    printf("%d\n",lcm(a,b));
  }
  return 0;
}
