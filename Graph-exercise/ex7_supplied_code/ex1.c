// Exercise 7 Graphs (Spring 2022)
// 1. Write a program to create and display a directed graph of N vertices using adjacency list.
// Also write the program to add and delete an edge from the graph.

#include <stdio.h>
#include <stdlib.h>


//declare a structure for adjacent node in an adjaceny list
struct adjListNode
{
    //the id of the node in a graph
    int id;
    //pointer points to the next element in the adjacency list
    struct adjListNode *next;
};

//declear a structure to present an adjacency list
//head is the pointer points to the first element in the list, i.e., a node in the graph.
struct adjList {
    struct adjListNode* head;
};

// declare a structure to represent a graph.
// N is the max number of nodes in graph.
// A graph is an array of adjacency lists.
struct graph {
    int N;
    struct adjList* array;
};



struct graph* createGraph(int);
void displayGraph(struct graph*);
void addEdge(struct graph* graph, int source, int target);
void deleteEdge(struct graph* graph, int source, int target);

struct graph* createGraph(int no_of_nodes){
   struct graph *new = malloc(sizeof(struct graph));
   new->N = no_of_nodes;
   new->array = malloc(sizeof(struct adjList) * no_of_nodes);

   for(int i = 0; i < no_of_nodes; i ++){
       struct adjListNode *head = malloc(sizeof(struct adjListNode));
       head->id = i;
       head->next = NULL;
       new->array[i].head = head;
   }
   return new;
}

void addEdge(struct graph* graph, int source, int target){
    for(int i = 0; i < graph->N;i ++){
        if(i == source){
            struct adjListNode *head = graph->array[i].head;

            struct adjListNode *new = malloc(sizeof(struct adjListNode));
            new->next = head->next;
            new->id = target;

            head->next = new;
            puts("Added");
        }
    }
}

void deleteEdge(struct graph* graph, int source, int target){

    for(int i = 0; i < graph->N;i ++){
        if(i == source){
            struct adjListNode *next = graph->array[i].head;
            while(next->next != NULL){
                if(next->next->id == target){
                    struct adjListNode *rem = next->next;
                    if(rem->next != NULL)
                        next->next = rem->next;
                    else
                        next->next = NULL;

                    free(rem);
                    return;
                }
                next = next->next;
            }
        }
    }
}

void displayGraph(struct graph* graph){
    for(int i = 0; i < graph->N;i ++){
        struct adjListNode *next = graph->array[i].head;
        while(next != NULL){
            if(next->next == NULL)
                printf("[%d]",next->id);
            else
                printf("[%d]->",next->id);
            next = next->next;
        }
        puts("");
    }
}


int main(void)
{
    int no_of_nodes = 4;

    struct graph* graph = createGraph(no_of_nodes);
    displayGraph(graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    puts("----");
    displayGraph(graph);

    deleteEdge(graph, 0, 1);

    puts("----");
    displayGraph(graph);

    return 0;
}





