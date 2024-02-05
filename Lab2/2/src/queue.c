#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>

struct queue* create_queue(){
    struct queue* new = malloc(sizeof(struct queue));

    if(new == NULL){
        exit(1);
    }

    new->front = NULL;
    new->rear = NULL;

    return new;
}

void enqueue(struct queue *q, struct task *t){
    //allocate new node
    struct node *new = malloc(sizeof(struct node));
    new->data = t;
    // if the queue is empty we set both front
    // and rear to the new node
    // else we set the old rears next
    // to our new rear
    if(is_empty(q)){
        q->front = new;
        q->rear = new;
    }else{
        q->rear->next = new;
        q->rear = new;
    }

}

struct task *dequeue(struct queue *q){
    struct node* front = q->front;

    if(front->next == NULL)
        q->rear = NULL;

    //this makes the front also NULL
    //if next is NULL
    q->front = front->next;

    struct task* t = front->data;
    free(front); // free the node

    return t;
}

void display_queue(struct queue *q){
    struct node* cur = q->front;
    while(cur != NULL){
        if(cur->data != NULL){
            printf("TASK [ %d pages, arrived at %d]\n",
                   cur->data->pages,
                   cur->data->time_stamp);
        }
        cur=cur->next;
    }
}

int is_empty(struct queue *q){
    return q->rear == NULL;
}
