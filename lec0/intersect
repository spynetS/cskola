// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

typedef struct block{
  double start,end;
} Block;

int isInside(Block* a, Block* b){
  return (a->end > b->start && a->start < b->end);
}

int main(){
  double t1,t2,t3,t4,t5,t6,t7,t8;
  while(scanf("%lf:%lf %lf:%lf %lf:%lf %lf:%lf",&t1,&t2,&t3,&t4,&t5,&t6,&t7,&t8)>0){
    Block a = {t1+t2/60,t3+t4/60};
    Block b = {t5+t6/60,t7+t8/60};

    if(isInside(&a,&b) || isInside(&b,&a)){
      puts("conflict");
    }
    else{
      puts("ok");
    }


  }
  return 0;
}
