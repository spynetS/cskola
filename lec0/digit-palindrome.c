// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void reverse(const char* src, char* dst){
  size_t len = strlen(src);
  int index = 0;
  for(int i = len-1; i >= 0;i--){
    dst[index] = src[i];
    index++;
  }
  dst[index]='\0';
}

int reverse_digits(int x){
    char buf[11];
    sprintf(buf,"%d",x);
    char reversed[11];
    reverse(buf, reversed);
    return atoi(reversed);
}
int palindrome(int x){
  return x == reverse_digits(x);
}
int main(){
  int input;
  while(scanf("%d",&input)>0){
    printf("%d is%s palindrome\n",input, palindrome(input) ? "" : " not");
  }
  return 0;
}
