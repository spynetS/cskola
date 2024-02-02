#include "queue.h"
#include <stdlib.h>

struct queue* create_queue(){
    return malloc(sizeof(struct queue));
}

void enqueue(struct queue *q, struct task *t){
    struct node *new = malloc(sizeof(struct node));

    new->data = t;
    new->next = q->rear;

    q->rear = new;
}

struct task *dequeue(struct queue *q){
    struct node *front = q->front;
    struct node *next = q->rear;
    while(next!=NULL){
    }
}
