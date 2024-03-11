#include "../include/heap.h"
#include <stdlib.h>

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
int weight(struct minheap* h, int index){
    if(index > h->cur_size) return -1; //return -1 if index is out of bounds

    return h->array[index]->dist;
}

void print_tree(struct minheap *h,int index, int level){
    if(righti(index) <= h->cur_size){
        print_tree(h,righti(index),level+1);
    }
    puts("");
    for(int i = 0; i < level; i ++){
        printf("-");
    }
    printf("%d",weight(h, index));
    if(lefti(index) <= h->cur_size){
        print_tree(h,lefti(index),level+1);
    }
}

struct minheap* create_heap(int max){
    struct minheap* new = malloc(sizeof(struct minheap));
    if(new == NULL) exit(1);

    new->pos = malloc(sizeof(int)*max);
    if(new->pos == NULL) exit(1);

    new->array = malloc(sizeof(struct minHeapNode)*max);
    if(new->array == NULL) exit(1);

    new->max_size = max;
    new->cur_size = 0;
    return new;
}

struct minHeapNode* new_min_heap_node(int n, int dist){
    struct minHeapNode* new = malloc(sizeof(struct minHeapNode));
    if(new == NULL) exit(1);
    new->graph_node_id = n;
    new->dist = dist;

    return new;
}

int insert_heap(struct minheap *h, struct minHeapNode *n){
    if(h->cur_size >= h->max_size) return 0;

    h->cur_size += 1;
    h->array[h->cur_size] = n;
    h->pos[n->graph_node_id] = h->cur_size;

    if(h->cur_size > 1){
        int index = h->cur_size;
        while(parenti(index) > 0 &&
        weight(h,parenti(index)) > weight(h,index)){
            struct minHeapNode* tmp = h->array[index];
            h->array[index] = h->array[parenti(index)];
            h->array[parenti(index)] = tmp;
            //update pos values
            h->pos[tmp->graph_node_id] = parenti(index);
            h->pos[h->array[index]->graph_node_id] = index;

            index = parenti(index);
        }
    }
    return 1;
}
int delete_heap(struct minheap *h){
    free(h->array[1]);

    h->array[1] = h->array[h->cur_size];
    h->array[h->cur_size] = NULL;
    h->cur_size --;
    int index = 1;
    // if weight of left is less then parent (index)
    // or weight of right is less then parent (index)
    while((weight(h, lefti(index)) < weight(h, index) && lefti(index) < h->cur_size) ||
          (weight(h, righti(index)) < weight(h, index) && righti(index) < h->cur_size))
    {
        //choose which to switch with,(if left is less we should switch with it)
        int childi = weight(h,lefti(index)) < weight(h,righti(index)) ? lefti(index) : righti(index);
        struct minHeapNode* tmp = h->array[childi];
        h->array[childi] = h->array[index];
        h->array[index] = tmp;

        //update the posses
        h->pos[tmp->graph_node_id] = index;
        h->pos[h->array[childi]->graph_node_id] = childi;

        index = childi;
    }
    return 1;
}

int is_empty(struct minheap *h){
    return h->cur_size == 0;
}

void display_heap(struct minheap *h){
    for(int  i = 1; i <= h->cur_size; i ++){
        printf("%d,",weight(h, i));
    }
    puts("");
    print_tree(h,1,1);
    puts("");
}

void destroy_heap(struct minheap *h){
    while(h->cur_size > 0){
        delete_heap(h);
    }
    free(h->pos);
    free(h->array);
    free(h);
}

void decreaseKey(struct minheap *h, int n, int dist){
    h->array[h->pos[n]]->dist = dist;
    int index = h->pos[n];

    while(parenti(index) > 0 && weight(h, parenti(index)) > weight(h,index))
    {
        struct minHeapNode* tmp = h->array[index];
        h->array[index] = h->array[parenti(index)];
        h->array[parenti(index)] = tmp;
        //update pos values
        h->pos[tmp->graph_node_id] = parenti(index);
        h->pos[h->array[index]->graph_node_id] = index;

        index = parenti(index);
    }
}

struct minHeapNode *findmin(struct minheap *h){
    if(h->cur_size == 0) {
        puts("UNDERFLOW");
        return NULL;
    }
    return h->array[0];
}
