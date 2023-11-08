// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
  return a+b;
}

int main(){
  int a,b;
  while(scanf("%d %d",&a,&b) == 2){
    printf("%d\n",add(a,b));
  }
  return 0;
}
