// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* whatTriangle(int a, int b, int c){
  if(a + b <= c || a+c <= b || b+c <= a) return "impossible";
  else if ((a == b && a != c) || (b == c && b != a) || (a == c && c !=b )) return "isosceles";
  else if (a != b && a != c ) return "scalene";
  else if (a==b && a == c) return "equilateral";
  else return "impossible";

}

double getAngle(double a, double b, double c){
  double rad = M_PI/180;
  double term = (pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b);
  return ( acos(term)/rad );
}
int cmpfunc (const void * a, const void * b) {
   return ( *(double*)a - *(double*)b );
}

char* triangleSidesType (double values[]){
  printf("%f\n",values[0]);

  qsort(values,3,sizeof(double),cmpfunc);

  int a = values[0];
  int b = values[1];
  int c = values[2];

  printf("%f\n",values[0]);

  printf("%f\n",getAngle(a,b,c));
  if (getAngle(a,b,c) == 90) return "right";
  else if (getAngle(a,b,c) > 90) return "obtuse";
  else return "acute";
}
int comp(const void* a, const void* b){
  return( *(int*) a > *(int*) b);
}

int main(){

  int a,b,c;
  while(scanf("%d %d %d",&a,&b,&c) == 3){
    char* pos = whatTriangle(a,b,c);
    int arr[] = {a, b, c};

    qsort(arr,3,sizeof(int),comp);

    if(strcmp(pos,"impossible")==0)
      printf("%s\n",pos);
    else
      printf("%s %s\n",pos,triangleSidesType(arr[0],arr[1],arr[2]));
  }
  return 0;
}
