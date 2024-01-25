// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digit_count(int d, int x){
  int sum = 0;
  char b[10];
  sprintf(b,"%d",x);
  for(int i = 0; i < strlen(b); i++){
    char buf[2];
    buf[0] = b[i];
    buf[1] = '\0';
    if(d == atoi(buf)) sum++;
  }

  return sum;
}

int main(){
  int a,b;
  while(scanf("%d %d",&a,&b) == 2){
    printf("%d\n",digit_count(a,b));
  }
  return 0;
}
