// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  double a,b;
  char operator;
  while(scanf("%lf %c %lf",&a,&operator,&b)>1){
    double ans=0;
    switch(operator){
      case '*':
        ans = a*b;
        break;
      case '/':
        ans = a/b;
        break;
      case '^':
        ans = pow(a,b);
        break;
      case '+':
        ans = a+b;
        break;
      case '-':
        ans = a-b;
        break;
    }
    printf("%.2lf\n",ans);
  }
  return 0;
}
