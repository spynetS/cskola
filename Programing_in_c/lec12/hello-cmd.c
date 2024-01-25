// 2023 Alfred Roos
#include <stdio.h>

int main(int argv,char **argc){
  if( argv > 0){
    printf("Hello, %s!\n",argc[1]);
  }
  return 0;
}
