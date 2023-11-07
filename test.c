
#include <stdio.h>
#include <stdlib.h>

void test(char* str){

  str[1] = 'c';
  str[2] = '\0';

}


int main(){

  char* name;
  *name = 's';
  printf("%c\n",*name);
  test(name);
  printf("%s\n",name);

    return 0;
}
