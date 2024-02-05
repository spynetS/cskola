#include "../include/task.h"
#include <stdlib.h>


struct task* create_task(int ct, int pages){
    struct task* new = malloc(sizeof(struct task));

    if(new == NULL){
        exit(1);
    }

    new->time_stamp = ct;
    new->pages = pages;
    return new;
}
