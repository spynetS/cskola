#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/task.h"
#include "../include/queue.h"
#include "../include/printer.h"

// simulation parameters
#define M  5
#define P  50
#define N  2
#define TASK_IN_N_SECOND  2

int main(){
    srand(time(NULL));
    struct queue* my_queue = create_queue(); // init queue on heap

    //init our printer on stack
    struct printer printer;
    printer.page_rate = P;
    printer.current_task = NULL;
    printer.time_remaining = 0;
    puts("Press enter to go forward in the simulation");
    // start simulation
    for(int i = 0; i < 10; i ++){
        printf("\nSIMULATION AT SECOND %d\n",i);
        puts(" ------------------------------");
        printer_status(&printer);

        printf("TASKS IN QUEUE:\n");
        display_queue(my_queue);

        // if printer is not bussy and we have tasks we start the task
        if(!is_busy(&printer) && !is_empty(my_queue)){
            start_next(&printer,dequeue(my_queue));
        }
        tick(&printer);

        // add a task randomly
        if(TASK_IN_N_SECOND == 1 + rand() % TASK_IN_N_SECOND){
            int pages = 1 + rand() % M;
            enqueue(my_queue, create_task(i,pages));
        }

        // what for enter so we can see whats happening
        getchar();
    }
    puts("SIMULATION ENDS");
    // free all our allocations
    if(printer.current_task != NULL){
        free(printer.current_task);
    }
    while(!is_empty(my_queue)){
        free(dequeue(my_queue));
    }
    free(my_queue);

    return 0;
}
