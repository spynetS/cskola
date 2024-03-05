// Alfred Roos 2024
#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 100
struct minheap{
    int last_i;
    struct task **elements;
};

//helper function to get the index depending on
//the child position
int lefti(int index){
    return index * 2;
}
int righti(int index){
    return index * 2 + 1;
}
int parenti(int index){
    return index/2;
}

int weight(struct minheap *h, int index){
    if(index > h->last_i) return -1; //return -1 if index is out of bounds

    return h->elements[index] != NULL ? h->elements[index]->pages : 6969;
}

void print_tree(struct minheap *h,int index, int level){
    if(righti(index) <= h->last_i){
        print_tree(h,righti(index),level+1);
    }
    puts("");
    for(int i = 0; i < level; i ++){
        printf("-");
    }
    printf("%d",weight(h, index));
    if(lefti(index) <= h->last_i){
        print_tree(h,lefti(index),level+1);
    }
}



struct minheap *create_heap(){
    struct minheap *new = malloc(sizeof(struct minheap));
    if(new == NULL) exit(1); // exit with error code
    new->last_i = 0; // (first will be in index 1)
    new->elements = malloc(sizeof(int)*MAX);
    new->elements[0] = NULL;
    return new;
}

int insert_heap(struct minheap *h, struct task *t){
    if(h->last_i >= MAX) return 0;

    printf("inserted aws %d\n",t->pages);

    h->last_i += 1;
    h->elements[h->last_i] = t;

    if(h->last_i > 1){
        int index = h->last_i;
        //as long parent is greater then us swap
        while(parenti(index) > 0 && weight(h, parenti(index)) > weight(h, index)){
            // swap parent and child
            struct task* tmp = h->elements[index];
            h->elements[index] = h->elements[parenti(index)];
            h->elements[parenti(index)] = tmp;
            index = parenti(index);
        }
    }
    return 1;
}

int delete_heap(struct minheap *h){
    // set root to last element and then removes the last
    free(h->elements[1]);
    h->elements[1] = h->elements[h->last_i];
    h->elements[h->last_i] = NULL;
    h->last_i --;

    int index = 1;
    while((weight(h, lefti(index)) < weight(h, index) && lefti(index) < h->last_i )||
          (weight(h, righti(index)) < weight(h, index) && righti(index) < h->last_i)){

        int childi = lefti(index) > righti(index) ? lefti(index) : righti(index);
        struct task *tmp = h->elements[childi];
        h->elements[childi] = h->elements[index];
        h->elements[index] = tmp;
        index = childi;
    }
    return 1;
}

struct task *findmin(struct minheap *h){
    return h->elements[1];
}

void destroy_heap(struct minheap *h){
    for(int i = 1; i <= h->last_i;i++){
        free(h->elements[i]);
    }
    free(h->elements);
    free(h);
}

void display_heap(struct minheap *h){
    for(int  i = 1; i <= h->last_i; i ++){
        printf("%d,",weight(h, i),i,h->last_i);
    }
    puts("");
    print_tree(h,1,1);
    puts("");
}

int is_empty(struct minheap *h){
    return h->last_i == 0;
}
