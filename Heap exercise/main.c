
//Exercise: Heaps  (Spring 2022)
// Write a program to implement a max binary heap queue.

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

//incomplete declaration to the structure
struct maxheap{
    int last_i;
    int *elements;
};

//create an empty binary heap
struct maxheap *create_heap();
//insert an element
//parameters: h, the pointer points to the heap.
//            key, the element to be inserted
void insert(struct maxheap *h, int key);
//delete an element
//parameters: h, the pointer points to the heap.
void delete(struct maxheap *h);
//find the maximun value in a heap
//parameters: h, the pointer points to the heap.
int findmax(struct maxheap *h);
//destroy a heap and release the space allocated to the heap
//parameters: h, the pointer points to the heap.
void destroy_heap(struct maxheap *h);
//prints the heap in the array
//parameters: h, the pointer points to the heap.
void print_heap(struct maxheap *h);


struct maxheap *create_heap(){
    struct maxheap *new = malloc(sizeof(struct maxheap));
    new->last_i = 0;
    new->elements = malloc(sizeof(int)*MAX);
    new->elements[0] = -1;
    return new;
}


void insert(struct maxheap* h, int key){
    h->last_i+=1;
    h->elements[h->last_i] = key;
    if(h->last_i > 1){
        int index = h->last_i;
        printf("me i:%d<%d> parent i:%d <%d>\n",index,h->elements[index],index/2,h->elements[index/2]);
        while(index/2 > 0 && h->elements[index] > h->elements[index/2]){
            printf("We %d are greater then parent %d\n",h->elements[index],h->elements[index/2]);
            int temp = h->elements[index/2];
            h->elements[index/2] = h->elements[index];
            h->elements[index] = temp;
            index = index/2;
        }
    }
}

void print_d(struct maxheap *h,int index){
    if((index*2+1) >= h->last_i){
        printf("%d",h->elements[index]);
    }else{
        print_d(h,index*2+1);
    }
}

void print_heap(struct maxheap *h){
    for(int  i = 1; i <= h->last_i; i ++){
        printf("%d,",h->elements[i]);
    }
    puts("");
    print_d(h,1);
}

int main(void) {

    //option: operation request from ueser input
    //val: data value
    int val, option;

    struct maxheap *heap = create_heap();

    do
    {
        printf("\n\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. FIND MAX VALUE");
        printf("\n 4. DESTROY");
        printf("\n 5. DISPLAY");
        printf("\n 6. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n Enter the number to be added to the heap: ");
                scanf("%d", &val);
                insert(heap,val);
                break;

            case 2:
                //delete(heap);
                break;

            case 3:
                //printf("The max value in the heap is %d. \n", findmax(heap));
                break;

            case 4:
                /* destroy_heap(heap); */
                //exit when the heap is destroyed.
                return 0;

            case 5:
                print_heap(heap);
                break;
        }
    //while not choose to exit
    }while(option != 6);

    return 0;
}
