// Alfred Roos 2024
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

int main1(){
    struct minheap* my_queue = create_heap(); // init queue on heap
    insert_heap(my_queue,create_task(0,2));
    insert_heap(my_queue,create_task(0,2));
    insert_heap(my_queue,create_task(0,3));
    insert_heap(my_queue,create_task(0,5));

    display_heap(my_queue);
    delete_heap(my_queue);

    display_heap(my_queue);
    destroy_heap(my_queue);

    return 0;
}

int main(){
    srand(time(NULL));
    struct minheap* my_queue = create_heap(); // init queue on heap

    //init our printer on stack
    struct printer printer;
    printer.page_rate = P;
    printer.current_task = NULL;
    printer.time_remaining = 0;
    int tasks = 0;
    puts("Press enter to go forward in the simulation");
    // start simulation
    for(int i = 0; i < 10; i ++){
        printf("\nSIMULATION AT SECOND %d\n",i);
        puts(" ------------------------------");
        printer_status(&printer);

        printf("%d TASKS IN QUEUE:\n",tasks);
        display_heap(my_queue);

        // if printer is not bussy and we have tasks we start the task
        if(!is_busy(&printer) && !is_empty(my_queue)){
            // we create a new task with the value of the min in our queue (i create a new because when we delete we free the min)
            struct task* pt = create_task(findmin(my_queue)->time_stamp,findmin(my_queue)->pages);
            delete_heap(my_queue);
            start_next(&printer,pt);
        }
        tick(&printer);

        // add a task randomly
        if(TASK_IN_N_SECOND == 1 + rand() % TASK_IN_N_SECOND){
            int pages = 1 + rand() % M;
            puts("ins");
            if(!insert_heap(my_queue, create_task(i,pages)))
                exit(1);
            tasks++;
        }

        // what for enter so we can see whats happening
        getchar();
    }
    puts("SIMULATION ENDS");
    // free all our allocations
    if(printer.current_task != NULL){
        free(printer.current_task);
    }

    destroy_heap(my_queue);

    return 0;
}
