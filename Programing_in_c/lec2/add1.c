// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *buffer = NULL;
    size_t len;
    while(getline(&buffer, &len, stdin)){
        printf(buffer);
        char buffer2[20];
        int count = 0;
        for(int i = 0; i < strlen(buffer)-1; i++){
            char chr = buffer[i];
            if(chr != ' '){
                buffer2[count] = chr;
            }
            else{
                printf("buffer was %s\n",buffer2);
                memset(buffer2,'\0', sizeof buffer2);
                count = -1;
            }
            count++;
        }
        printf("buffer was %d\n",atoi(buffer2));
        memset(buffer2,'\0', sizeof buffer2);

        buffer = NULL;
    }
    free(buffer);

    return 0;
}
