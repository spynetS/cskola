// Alfred Roos 2024
#include "lab_lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 60
#define PHONENUMBER_SIZE 11

struct node {
    char* phonenumber;
    char* name;
    struct node* next;
};


void print_node(struct node* node){
    if(node != NULL){

        printf("Name: %s; Phonenumber: %s\n",node->name, node->phonenumber);
    }
}
void display(struct node *start){
    struct node* next = start;
    while(next != NULL){
        print_node(next);
        next = next->next;
    }
}

int query_directory_list(struct node** nodes, struct node *start, char* search, int option){
    // we go though all the nodes and whether
    // the option is one or 2 we check the
    // phonenumber or the name with num/name.
    // If we find a match we return that node
    int count = 0;
    struct node* next = start;
    while(next != NULL){
        switch(option){
            case 1:
                if(strcmp(next->phonenumber,search)==0){
                     nodes[count] = next;
                     count ++;
                }
                break;
            case 2:
                if(strcmp(next->name,search)==0){
                     nodes[count] = next;
                     count ++;
                }
                break;
            default:
                if(strcmp(next->name,search)==0 || strcmp(next->phonenumber,search) == 0){
                     nodes[count] = next;
                     count ++;
                }
        }
        next = next->next;
    }
    return count;
}
struct node *query_directory(struct node *start, char* num, char *name, int option){
    // we go though all the nodes and whether
    // the option is one or 2 we check the
    // phonenumber or the name with num/name.
    // If we find a match we return that node
    struct node* next = start;
    while(next != NULL){
        switch(option){
            case 1:
                if(strcmp(next->phonenumber,num)==0){
                    return next;
                }
                break;
            case 2:
                if(strcmp(next->name,name)==0){
                    return next;
                }
                break;
        }
        next = next->next;
    }
    return NULL;
}

int record_exists(struct node *start,char* num){
    return query_directory(start,num,"",1) != NULL;
}

int insert_record(struct node **start){

    // we fetch data from terminal
    char name[NAME_SIZE];
    char phonenumber[PHONENUMBER_SIZE];

    printf("Record name: ");
    scanf("%[^\n]s",name);
    printf("Record phonenumber: ");
    scanf("%s",phonenumber);

    // if the record exists we free the new node and return -1
    if(record_exists(*start,phonenumber)){
        return -1;
    }
    // create a new node and set its values from terminal
    struct node *new = malloc(sizeof(struct node));
    if(new == NULL) return -1; // malloc fail

    new->name = malloc(sizeof(char) * strlen(name));
    new->phonenumber = malloc(sizeof(char) * strlen(phonenumber));
    strcpy(new->name,name);
    strcpy(new->phonenumber,phonenumber);

    // if the start is not null we set so the new
    // node points to that node
    // and then we set the so the start is our new
    if(*start != NULL){
        new->next = *start;
    }
    *start = new;

    return 0;
}
int delete_record_name(struct node **start, char* name){
    struct node *next = *start;
    struct node *prev = NULL;
    while(next != NULL){
        // if the phonenumber is the same as the num we set
        // prevs next to the next next
        // and free the current next and then return success
        if(strcmp(next->name,name) == 0){
            struct node* temp = next;
            // if it is the first we are deleting
            // prev will be null then we just set start
            // to be next next
            if(prev != NULL){
                prev->next = next->next;
            }
            else {
                *start = next->next;
            }

            free(temp->name);
            free(temp->phonenumber);
            free(temp);
        }
        else{
            prev = next;
        }
        next = next->next;
    }

    return -1;
}
int delete_record(struct node **start, char* num){
    struct node *next = *start;
    struct node *prev = NULL;
    while(next != NULL){
        // if the phonenumber is the same as the num we set
        // prevs next to the next next
        // and free the current next and then return success
        if(strcmp(next->phonenumber,num) == 0){
            struct node* temp = next;
            // if it is the first we are deleting
            // prev will be null then we just set start
            // to be next next
            if(prev != NULL){
                prev->next = next->next;
            }
            else {
                *start = next->next;
            }

            free(temp->name);
            free(temp->phonenumber);
            free(temp);
            return 0;
        }
        prev = next;
        next = next->next;
    }
    // no record found return -1 error
    return -1;
}
void delete_directory(struct node **start){
    struct node* next = *start;
    while(next != NULL){
        //create a temp so we can free the memory
        struct node *this = next;
        next = next->next;

        free(this->name);
        free(this->phonenumber);
        free(this);
    }
}
