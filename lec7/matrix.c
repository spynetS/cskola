// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int *src, int size){
  for(int i = 0 ; i < size*size; i ++){
    if(i>0&&i % size == 0) printf("\n");
    printf("%d ",src[i]);
  }
}

int multRowCol(int *row, int *col, int size){
  int sum = 0;
  for(int i = 0; i < size;i ++){
    sum += row[i]*col[i];
  }
  return sum;
}

void multiply(int *term1, int *term2, int size,int *sum){

  int row[size];
  int col[size];
  int count = 0;
  for(int i = 0 ; i < size;i++){
    row[count] = term1[i];
  }

  printMatrix(sum,size);
}

int main(){
  int size;
  while(scanf("%d",&size)>0){
    int term1[size*size];
    for(int i = 0 ; i < size*size; i ++){
      int temp;
      scanf("%d",&temp);
      term1[i]=temp;
    }
    int term2[size*size];
    for(int i = 0 ; i < size*size; i ++){
      int temp;
      scanf("%d",&temp);
      term2[i]=temp;
    }
    int dst[size*size];
    multiply(term1,term2,size,dst);
  }
  return 0;
}
/*
1 3 | 4 2
3 7 | 4 2


*/
