#include "../include/graph.h"
#include <stdlib.h>

struct graph* createGraph(int number_of_nodes){
    struct graph* new = malloc(sizeof(struct graph));
    if(new == NULL) exit(1);

    new->array = malloc(sizeof(struct adjList)*number_of_nodes);
    if(new->array == NULL) exit(1);
    for(int i = 0; i < number_of_nodes; i ++){
        struct adjListNode* head = malloc(sizeof(struct adjListNode));
        head->graph_node_id = i;
        head->next = NULL;
        head->weight = 0;
        new->array[i].head = head;
    }

    new->N = number_of_nodes;

    return new;
}

void displayGraph(struct graph *graph, char **cities){
    puts("[id;weight]");
    for(int i = 0; i < graph->N;i++){
        struct adjListNode* tmp = graph->array[i].head;
        while(tmp!=NULL){
            printf("[%d|%d]->",tmp->graph_node_id,tmp->weight);
            tmp = tmp->next;
        }
        puts("");
    }
}

void addEdge(struct graph* graph, int source, int target, int weight){
    for(int i = 0; i < graph->N; i ++){
        if(graph->array[i].head->graph_node_id == source){
            // create new node and set its next to be the head
            // and then replace the head with the new
            struct adjListNode *new = malloc(sizeof(struct adjListNode));
            new->graph_node_id = target;
            new->weight = weight;
            new->next = NULL;
            if(graph->array[i].head->next != NULL){
                new->next = graph->array[i].head->next;
            }
            graph->array[i].head->next = new;

            return;
        }
    }
}

void deleteEdge(struct graph* graph, int source, int target){
    for(int i = 0; i < graph->N; i ++){
        if(graph->array[i].head->graph_node_id == source){
            struct adjListNode* tmp = graph->array[i].head;
            struct adjListNode* prev = NULL;
            while(tmp!=NULL){
                if(tmp->graph_node_id == target){
                    struct adjListNode *ptr = tmp;
                    if(prev!=NULL)
                        prev->next = tmp->next;
                    else
                        graph->array[i].head = tmp->next;

                    free(ptr);
                }
                tmp=tmp->next;
            }
        }
    }

}
