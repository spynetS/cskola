//2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int list_size = 0;
    int *list = (int*)malloc(sizeof(int)*100);

    char code[100];
    while(scanf("%s",code)>0){
        if(strcmp(code,"push")==0){
            int value;
            scanf("%d",&value);
            list[list_size] = value;
            list_size++;
        }
        else if (strcmp(code,"pop")==0){
            if(list_size > 0){
                printf("%d\n",list[list_size-1]);
                list_size --;
            }else{
                printf("empty\n");
            }
        }
    }
    return 0;
}
