// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct rect{
  int x,y,a,b;
} Rect;

int isInside(Rect* rect1, Rect* rect2){
  return(rect1-> a < rect2->x || rect2->a<rect1->x || rect1->b< rect2->y || rect2->b<rect1->y);
    /* return(rect1->x < rect2->x + rect2->w && */
    /* rect1->x + rect1->w > rect2->x && */
    /* rect1->y < rect2->y + rect2->h && */
    /* rect1->y + rect1->h > rect2->y); */
}

int main(){
  int i1,i2,i3,i4,i5,i6,i7,i8;
  while(scanf("%d %d %d %d %d %d %d %d",&i1,&i2,&i3,&i4,&i5,&i6,&i7,&i8)>0){
    /* Rect a = {i1,i2,abs(i1-i3),abs(i2-i4)}; */
    /* Rect b = {i5,i6,abs(i5-i7),abs(i6-i8)}; */
    Rect a = {i1,i2,i3,i4};
    Rect b = {i5,i6,i7,i8};

    if(!isInside(&a,&b)){
      puts("yes");
    }
    else{
      puts("no");
    }

  }
  return 0;
}
