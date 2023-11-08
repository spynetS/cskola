// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//i define true and false and bool to get cleaner code hehe
#define TRUE 1
#define FALSE 0
#define bool int

bool and (bool i1, bool i2){
  return i1 == TRUE && i1==i2;
}
bool or (bool i1, bool i2){
  return i1 == TRUE ? i1 : i2;
}
bool xor (bool i1, bool i2){
  return i1==i2? FALSE:TRUE;
}
bool not(bool i){
  return i==TRUE?FALSE:TRUE;
}
bool implies (bool i1, bool i2){
  return or(not(i1),i2 );
}


int main(){
  char value1[6];
  char operator[8];
  char value2[6];
  //get first words
  while(scanf("%s",value1)>0 && scanf("%s",operator)>0){
    bool result=0;
    bool v1 = strcmp(value1, "true") == 0;
    bool v2 = strcmp(operator, "true") == 0;
    // if the first word is not not we get the last value
    // thi is because not <value> exist which only takes 2 words
    if(strcmp(value1,"not") != 0){
      scanf("%s",value2);
      v2 = strcmp(value2, "true") == 0;

    }

    if(strcmp(operator,"and") == 0)           result = and(v1,v2);
    else if(strcmp(operator,"or") == 0)       result = or(v1,v2);
    else if(strcmp(operator,"xor") == 0)      result = xor(v1,v2);
    else if(strcmp(operator,"implies") == 0)  result = implies(v1,v2);
    else result = not(v2);

    printf("%s\n",result == TRUE?"true":"false");
  }
  return 0;
}
