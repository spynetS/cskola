// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){
  //time start 0 hour, time end 0 minutes ...
  float ts0h,ts0m,te0h,te0m,ts1h,ts1m,te1h,te1m;
  while(scanf("%f:%f %f:%f %f:%f %f:%f",&ts0h,&ts0m,&te0h,&ts1h,&ts1m,&te0m,&te1h,&te1m) > 0){

    double startA = ts0h+ts0m/60; //start h
    double endA= te0h+te0m/60;  //end h

    double startB = ts1h+ts1m/60; // start h
    double endB = te1h+te1m/60; // end h

    if(startA > startB){
      if(startA < endB) printf("conflict\n");
      else printf("ok\n");
    }
    else{
      if(startB < endA) printf("conflict\n");
      else printf("ok\n");
    }



  }
  return 0;
}
