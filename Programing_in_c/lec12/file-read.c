// 2023 Alfred Roos

#include <stdio.h>

int main(){
    FILE *fptr;
    fptr = fopen("name.txt","r");
    if(fptr == NULL){
        printf("name.txt: file not found\n");
        return 0;
    }
    char word[100];
    fscanf(fptr,"%s",word);
    printf("%s\n",word);
    fclose(fptr);

    return 0;
}
