// Alfred Roos 2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack Stack;

char peek(Stack *stack);
char pop(Stack *stack);
int push(Stack *stack, char item);

int is_open(char ch, char* all);
char get_closing(char open, char *all);
int get_weight(char tag, char *all);
void STOP(Stack* stack);

// STACK IMPLEMENTATION **

typedef struct stack{
    char *list;
    int max;
    int length;
} Stack;

char peek(Stack *stack){
    if(stack->length > 0){
        char to_ret = stack->list[stack->length-1];
        return to_ret;
    }
    return 0;
}

char pop(Stack *stack){
    if(stack->length > 0){
        stack->length --;

        char to_ret = stack->list[stack->length];
        stack->list[stack->length] = '\0';
        return to_ret;
    }
    return 0;
}
int push(Stack *stack, char item){
    if(stack->length != stack->max){
        stack->list[stack->length] = item;
        stack->length ++;
        return 1;
    }

    // max length
    return 0;
}

// ** HELPER FUNCTIONS FOR THE PROGRAM **

// 1 if it is a open
// 0 if it is a closing bracket
//-1 if it is neither
int is_open(char ch, char* all){
    for(int i = 0; i < strlen(all); i ++){
        // if the index is even it is a start tag
        // (the tags should be sort opentag,closetag,opentag,closetag)
        if(all[i] == ch) return (i % 2 == 0) ? 1 : 0;
    }
    return -1;
}

// we return the next char int the tags array
// (the tags should be sort opentag,closetag,opentag,closetag)
char get_closing(char open, char *all){
    for(int i = 0; i < strlen(all); i ++){
        if(all[i] == open && i+1 < strlen(all)) return all[i+1];
    }
    return 0;
}
// returns the index where the tag is found
// because the tags list is sorted by greates 'weight' (low->high)
// we can do this and compare
int get_weight(char tag, char *all){
    for(int i = 0; i < strlen(all); i++){
        if(all[i] == tag){
            return i;
        }
    }
    return -1;
}

// exits the program
void STOP(Stack* stack){
    puts("Invalid expression!");
    free(stack->list);
    exit(1);
}

int main(){
    int size = 100;
    printf("Enter an parenthese string (max %d characters): ",size);
    char input[size];
    // sorted bracket list by 'weight'
    char tags[] = {'(',')','[',']','{','}','\0'};

    scanf("%s", input);

    //init our stack
    Stack stack;
    stack.max = size;
    stack.length = 0;
    stack.list = malloc(sizeof(char)*size);


    for(int i = 0; i < strlen(input);i++){
        char curr = input[i];
        char top = '\0'; // use in switch
        // check if the curr char is a open or closing tag
        switch(is_open(curr, tags)){
            case 1:
                top = peek(&stack);
                // if the one we want to add is 'less' then the top
                // it is a error '[ cant be in ( but ( can be in ['
                // ([])   ilegal
                // [()]   legal
                // {[()]} legal
                // {([])} ilegal
                if(top == 0 || get_weight(top,tags) >= get_weight(curr, tags)){
                    push(&stack, curr);
                }else{
                    STOP(&stack);
                }
                break;
            case 0:
                // if the top is empty error
                // if the curr char is not closing tag to
                top = peek(&stack);
                if(top != 0 && curr == get_closing(top,tags)){
                    pop(&stack);
                }
                else{
                    STOP(&stack);
                }
                break;
        }

    }

    // if we have things in the stack still
    // we have a error
    if(stack.length > 0)
        STOP(&stack);

    puts("Balanced!");
    free(stack.list);

    return 0;
}
