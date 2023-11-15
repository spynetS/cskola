// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(int *src, int size){
  for(int i = 0 ; i < size; i ++){
    if(i>0&&i % (int) pow(size,0.5) == 0) printf("\n");
    printf("%d ",src[i]);
  }
}

void getRow(int *matrix,int *dst, int size,int pos){
  for(int i = 0; i < size;i ++){
    int index = i+size*pos;
    dst[i] = matrix[index];
  }
}
void getCol(int *matrix,int *dst, int size,int pos){
  for(int i = 0; i < size;i ++){
    int index = pos+size*i;
    dst[i] = matrix[index];
  }
}

int multiplyRowCol(int *row,int *col,int size){
  int sum = 0;
  for(int j = 0; j < size; j ++){
    sum += row[j]*col[j];
  }
  return sum;
}

void multiply(int *term1, int *term2, int size,int *sum){

  int count = 0;
  int row[size];
  int col[size];

  for(int i = 0; i < size; i ++){
    for(int j = 0; j < size; j ++){
      // get the row from first matrix
      getRow(term1,row,size,i);
      // get col from second matrix
      getCol(term2,col,size,j);
      //set the sum to the product of the row and colum
      sum[count] = multiplyRowCol(row,col,size);
      count++;
    }
  }
  printMatrix(sum,size*size);
  printf("\n");
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
