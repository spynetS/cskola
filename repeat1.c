// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>


int main(){

    char *buffer = NULL;
    int read;
    size_t len;
    read = getline(&buffer, &len, stdin);
    printf(buffer);

    free(buffer);
    return 0;
}
