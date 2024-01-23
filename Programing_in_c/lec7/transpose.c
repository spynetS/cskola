// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int *src, int size){
  for(int i = 0 ; i < size*size; i ++){
    if(i>0&&i % size == 0) printf("\n");
    printf("%d ",src[i]);
  }
}

void transpose(int *src,int *dst,int size ){
  for(int i = 0 ; i < size*size; i ++){
    //dst[i] = src[i];
  }
  for(int y = 0 ; y < size; y ++){
    for(int x = y ; x < size; x ++){
      int index = (size)*x+y;
      //printf("%d: %d->%d\n",x+(size*y),src[index],src[x+(size*y)]);
      dst[x+size*y] = src[index];
      dst[index]= src[x+size*y];
    }
    //printf("\n");
  }
}

int main(){

  int size;
  while(scanf("%d",&size)>0){
    int src[size*size];
    int count = 0;
    for(int j = 0; j < size; j++){
      for(int i = 0; i < size; i++){
        int temp;
        scanf("%d",&temp);
        src[count]=temp;
        count++;
      }
    }
    int transposed[size*size];
    transpose(src,transposed,size);

    printMatrix(transposed,size);
    printf("\n");
  }

  return 0;
}

/*
0  0  1  2  3  4
0
0  1  2  3  4  5
1  6  7  8  9  10
2  11 12 13 14 15
3  16 17 18 19 20
4  21 22 23 24 25

*/
