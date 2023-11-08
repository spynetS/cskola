// 2023 Alfred Roos
#include <stdio.h>

int volume(int a, int b,int c){
  return a * b * c;
}

int area(int a, int b, int c){
  return 2*a*b + 2*a*c + 2*b*c;
}

int main(){

  int a,b,c;
  scanf("%d %d %d", &a, &b, &c);

  printf("The volume of a %d by %d by %d box is %d.\n",
         a,
         b,
         c,
         volume(a,b,c)
         );
  printf("The surface area of a %d by %d by %d box is %d.\n",
         a,
         b,
         c,
         area(a,b,c)
         );

  return 0;
}
