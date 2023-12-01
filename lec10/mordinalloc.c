// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * ordinal(int n);

char* suffix(int n){
  int num = n % 10;

  if(((n / 10 ) % 10 ) == 1) return "th";

  switch(num){
    case 1:
      return "st";
    case 2:
      return "nd";
    case 3:
      return "rd";
  }
  return "th";
}

int main(){
  int num;
  while(scanf("%d",&num)>0){
    char* val = ordinal(num);
    printf("%s\n",val);
    free(val);
  }
  return 0;
}

char * ordinal(int n){
  int length = n > 0 ? log(n) : 1;
  char* val = (char*)malloc(sizeof(char) * (length+3));
  char* suf = suffix(n);

  sprintf(val,"%d%s",n,suf);
  return val;
}
