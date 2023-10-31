// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){
  int a;
  while(scanf("%d",&a)==1){
    if(a >= 4 && a <= 11) printf("Good morning\n");
    else if(a >= 12 && a <= 17) printf("Good afternoon\n");
    else if(a >= 18 && a <= 23) printf("Good evening\n");
    else printf("Hi\n");
  }
  return 0;
}
