// 2023 Alfred Roos
#include <stdio.h>


int main(){

    FILE *fptr;
    int times = 0;
    fptr = fopen("runcount.txt","r");

    if(fptr != NULL){
        fscanf(fptr,"%d",&times);
        fclose(fptr);
    }
    printf("run #%d\n",times);

    fptr = fopen("runcount.txt","w");
    fprintf(fptr,"%d",times+1);
    fclose(fptr);

    return 0;
}
