// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int digit_sum(int x){
  int sum = 0;
  char b[10];
  sprintf(b,"%d",x);
  for(int i = 0; i < strlen(b); i ++){
    char buf[2];
    buf[0] = b[i];
    buf[1] = '\0';

    sum += atoi(buf);
  }

  return sum;
}

int main(){
  int a;
  while(scanf("%d",&a) == 1 ){
    printf("%d\n",digit_sum(a));
  }
  return 0;
}
