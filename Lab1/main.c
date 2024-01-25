// Alfred Roos 2024
#include <stdio.h>
#include <stdlib.h>
#include "lab_lists.h"
#include <string.h>

#define RESET "\x1b[0m"
#define RED    "\x1b[31m"
#define GREEN  "\x1b[32m"

int main(){

    // the root node
    struct node *directory = NULL;

    printf("help for help/ exit to exit\n");
    // program loop
    while(1){
        printf("> ");

        char cmd[10];
        scanf("%9s",cmd);

        if(strcmp(cmd, "insert") == 0){
            if(insert_record(&directory)){
                printf(RED"phonenumber allready exists!\n"RESET);
            }
        }
        else if(strcmp(cmd, "rm") == 0){
            char num[11];
            scanf("%s",num);
            delete_record(&directory,num);
        }
        else if(strcmp(cmd, "ls") == 0){
            display(directory);
        }
        else if(strcmp(cmd, "find") == 0){

            char search_string[60];
            scanf("%s", search_string);

            //search for phonenumber, if it is null search of name else not found
            struct node *found = query_directory(directory,search_string,search_string,1);
            if(found != NULL){
                print_node(found);
            }
            else{
                found = query_directory(directory,search_string,search_string,2);
                if(found != NULL){
                    print_node(found);
                }
                else{
                    printf("not found\n");
                }
            }
        }

        else if(strcmp(cmd,"help") == 0){
            printf("Avalible commands\n");
            printf(" insert                  -- Add new record\n");
            printf(" rm [phonenumber]        -- removed record with phonenumber\n");
            printf(" ls                      -- list records\n");
            printf(" find [name/phonenumber] -- prints record with name/phonenumber\n");
            printf(" exit                    -- exit program\n");
        }
        else if(strcmp(cmd,"exit") == 0){
            break;
        }
        else{
            printf("command not recognized\n");
        }
    }
    delete_directory(&directory);

    return 0;
}
