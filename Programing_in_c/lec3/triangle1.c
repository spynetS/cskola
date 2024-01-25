// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

char* whatTriangle(int a, int b, int c){
  if(a + b <= c || a+c <= b || b+c <= a) return "impossible";
  else if ((a == b && a != c) || (b == c && b != a) || (a == c && c !=b )) return "isosceles";
  else if (a != b && a != c ) return "scalene";
  else if (a==b && a == c) return "equilateral";
  else return "impossible";

}

int main(){

  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  printf("%s\n",whatTriangle(a,b,c));

  return 0;
}
