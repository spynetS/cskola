// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
int volume(int w, int h, int d){
  return w*h*d;
}
int area(int w, int h, int d){
  return 2*d*h+2*d*h+2*w*h;
}
int main(){
  int w,h,d;
  while(scanf("%d%d%d",&w,&h,&d)>0){
    printf("The volume of a %d by %d by %d box is %d.\n",w,h,d,volume(w,h,d));
    printf("The surface area of a %d by %d by %d box is %d.\n\n",w,h,d,area(w,h,d));

  }
  return 0;
}
