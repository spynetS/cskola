#include "libmult.h"
#include <stdio.h>

int main(){

    int x;
    scanf("%d",&x);
    printf("triple(%d) = %d\n",x,triple(x));
    printf("quadruple(%d) = %d\n",x,quadruple(x));
    printf("quintuple(%d) = %d\n",x, quintuple(x));
    printf("sixtuple(%d) = %d\n",x, sixtuple(x));
    printf("septuple(%d) = %d\n",x, septuple(x));

}
