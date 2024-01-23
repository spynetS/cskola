// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int inc(int x){
    return x +1;
}

int main(){

    char *buffer = NULL;
    int read;
    size_t len;
    read = getline(&buffer, &len, stdin);
    int x = atoi(buffer);

    printf("%d\n",inc(x));

    free(buffer);
    return 0;
}
