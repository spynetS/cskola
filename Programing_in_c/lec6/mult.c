// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
int mult(int x, int y, int z){
  return x*y*z;
}
int main(){
  int a,b,c;
  while(scanf("%d%d%d",&a,&b,&c)>0){
    printf("%d\n",mult(a,b,c));
  }
  return 0;
}
