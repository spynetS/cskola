// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *getThing(int money){
  int hundreds = money/100;
  int tenvalue = money-(hundreds*100);
  int onevalue = tenvalue-(tenvalue/10)*10;
  int fiftys = 0;
  int twenties = 0;
  int tens = 0;
  int fives = 0;
  int twos = 0;
  int ones = 0;
  //calulate the tens place
  while(tenvalue/10 > 0){
    if(tenvalue - 50 >= 0){
      tenvalue-=50;
      fiftys++;
    }
    else if (tenvalue - 20 >= 0){
      tenvalue-=20;
      twenties++;
    }
    else if (tenvalue - 10 >= 0){
      tenvalue-=10;
      tens++;
    }
  }
  while(onevalue > 0){
    if(onevalue - 5 >= 0){
      onevalue-=5;
      fives++;
    }
    else if(onevalue - 2 >= 0){
      onevalue-=2;
      twos ++;
    }
    else if(onevalue - 1 >= 0){
      onevalue-=1;
      ones ++;
    }
  }
  char *buffer = malloc(sizeof(char)*100);
  if(hundreds > 0) sprintf(buffer,"%s %dx100",buffer,hundreds);
  if(fiftys > 0)   sprintf(buffer,"%s %dx50",buffer,fiftys);
  if(twenties > 0) sprintf(buffer,"%s %dx20",buffer,twenties);
  if(tens > 0)     sprintf(buffer,"%s %dx10",buffer,tens);
  if(fives > 0)    sprintf(buffer,"%s %dx5",buffer,fives);
  if(twos > 0)     sprintf(buffer,"%s %dx2",buffer,twos);
  if(ones > 0)     sprintf(buffer,"%s %dx1",buffer,ones);
  //move the pointer to remove the first char (which is a space)
  buffer++;
  return buffer;
}

int main(){
  int money;
  while(scanf("%d",&money)>0){
    printf("%s\n",getThing(money));
  }
  return 0;
}
