// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double circumference(double r){
  return 2*M_PI*r;
}
double area(double r){
  return M_PI*r*r;
}

int main(){
  double r;
  while(scanf("%lf",&r)==1){
    printf("%.2f %.2f\n",circumference(r), area(r));
  }
  return 0;
}
