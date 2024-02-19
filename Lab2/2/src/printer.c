// Alfred Roos 2024
#include "../include/printer.h"
#include <stdio.h>
#include <stdlib.h>


void tick(struct printer *p){
    if(p->current_task != NULL){
        // if the time is 0 we should remove the
        // current task
        // else we decrese the time
        if(p->time_remaining == 0){
            free(p->current_task);
            p->current_task = NULL;
        }else{
            p->time_remaining --;
        }
    }
}

int is_busy(struct printer *p){
    return p->current_task != NULL;
}

void start_next(struct printer *p, struct task *t){
    // if we are not busy, if current_task is not null,
    // free current_task and set it to the new
    if(!is_busy(p)){
        if(p->current_task != NULL)
            free(p->current_task);
        p->current_task = t;
        p-> time_remaining = t->pages * (60/p->page_rate);
    }
}

void printer_status(struct printer *p){
    if(!is_busy(p))
        printf("THE PRINTER IS NO LONGER BUSY\n");
    else
        printf("THE PRINTER IS BUSY\n");
    printf("TIME REMAINING %u\n",p->time_remaining);
}
