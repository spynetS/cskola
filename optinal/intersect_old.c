// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct rect{
  int x,y;
  int w,h;
} Rect;

int main(){
  int i1,i2,i3,i4,i5,i6,i7,i8;
  //           x1 y1 x2 y2 ---++++----
  while(scanf("%d %d %d %d %d %d %d %d ",&i1,&i2,&i3,&i4,&i5,&i6,&i7,&i8) > 0){
    Rect rect1 = {i1,i2,abs(i1-i3),abs(i2-i4)};
    Rect rect2 = {i5,i6,abs(i5-i7),abs(i6-i8)};

    if(rect1.x < rect2.x + rect2.w &&
    rect1.x + rect1.w > rect2.x &&
    rect1.y < rect2.y + rect2.h &&
    rect1.y + rect1.h > rect2.y){
      printf("yes\n");
    }
    else printf("no\n");
  }
  return 0;
}
