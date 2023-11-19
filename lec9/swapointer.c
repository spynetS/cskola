// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

void swap(int *px, int *py){
  int tmp = *px;
  *px=*py;
  *py=tmp;
}

int main(){
  int a,b;
  while(scanf("%d %d",&a,&b)>0){
    swap(&a,&b);
    printf("%d %d\n",a,b);

  }
  return 0;
}
