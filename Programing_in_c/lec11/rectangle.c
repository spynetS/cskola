// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

struct rectangle{
  int width, height;
};

int area(struct rectangle rectangle){
  return rectangle.width*rectangle.height;
}
int perimeter(struct rectangle rectangle){
  return 2*(rectangle.width+rectangle.height);
}



int main(){
  int a,b;
  while(scanf("%d %d",&a, &b)>0){
    struct rectangle rectangle = {a,b};
          //<W>x<H> rectangle, area = <AREA>, perimeter = <PERIMETER>
    printf("%dx%d rectangle, area = %d, perimeter = %d\n",a,b,area(rectangle),perimeter(rectangle));
  }

  return 0;
}
