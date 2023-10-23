#include <stdio.h>
#include <stdlib.h>

int main(){


  while(1){
    char* test = malloc(sizeof(char)*100);
    free(test);
  }

}
