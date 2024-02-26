/* This source code is from the texbook Data Structures Using C, 2nd edition,
 * by Reema Thareja, Oxford University Press, 2014.
 * The detailed comments and references to the lecture slides are added by Vladimir Tarasov
 * Data Structures, 7.5 credits, Spring 2022.
 */

#include <stdio.h>
#include <stdlib.h>
#include "./lab_binary_trees.h"

// A structure implementing a node of an AVL tree.
struct node
{
    int data;
    int balance;
    struct node *left;
    struct node *right;
};

struct node *search(struct node *ptr, int data)
{
    if (ptr != NULL){
        if (data < ptr->data)
            ptr = search(ptr->left, data);
         else if(data > ptr->data)
             ptr = search(ptr->right, data);
    }
    return (ptr);
}

// A function to insert a new element into an AVL tree.
struct node *insert(int data, struct node *tree, bool *ht_inc)
{
    // ht_inc is a tricky variable. It is set to TRUE after a new node is inserted
    // as a leaf, which means that a re-balancing might be needed at a hihger
    // level of a tree, where the critical node resides. When re-balancing is  
    // done or will not be needed at a hihger level, ht_inc is set to FALSE.
    struct node *aptr, *bptr;
    if (tree == NULL)
    {
        tree = (struct node *)malloc(sizeof(struct node));
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
        tree->balance = 0;
        *ht_inc = TRUE; // a new node is a added
        return (tree);
    }
    // A new node is inserted as a leaf.
    // First find where to add it by following the BST order
    // Then check the balance factor
    // Finally perform a rebalancing rotation
    if (data < tree->data)
    {
        // Insert in the left sub-tree
        tree->left = insert(data, tree->left, ht_inc);
        if (*ht_inc == TRUE) // a re-balancing might be needed
        {
            // Check the balance factor after the insertion
            switch (tree->balance)
            {
            case -1: /* Right heavy */
                // the node was right heavy and after insertion has become balanced.
                tree->balance = 0;
                *ht_inc = FALSE; // re-balancing will not be needed at a hihger level
                break;
            case 0: /* Balanced */
                // the node was balanced and after insertion has become left heavy.
                tree->balance = 1;
                break;
            case 1: /* Left heavy */
                // the node was left heavy and after insertion has become an unbalanced sub-tree.
                // Rebalancing rotation is needed - determine the type of rotation
                // Check the left sub-tree
                aptr = tree->left; // "tree" is A and "aptr" is B (see Fig. 10.40 in the textbook)
                if (aptr->balance == 1)
                {
                    // LL rotation: the new node is inserted in the left sub-tree of
                    // the left sub-tree of the critical node
                    printf("Left to Left Rotation\n");
                    tree->left = aptr->right; // T2 is made left sub-tree of A (see Fig. 10.40 in the textbook)
                    aptr->right = tree;             // A is made right sub-tree of B (see Fig. 10.40 in the textbook)
                    tree->balance = 0;
                    aptr->balance = 0;
                    tree = aptr; // B is moved up to the A-place (see Fig. 10.40 in the textbook)
                }
                else
                {
                    // LR rotation: the new node is inserted in the right sub-tree of
                    // the left sub-tree of the critical node
                    printf("Left to Right rotation\n");
                    bptr = aptr->right;             // "bptr" is C (see Fig. 10.44 in the textbook)
                    aptr->right = bptr->left; // T2 is made right sub-tree of B (see Fig. 10.44 in the textbook)
                    bptr->left = aptr;              // B is made left sub-tree of C (see Fig. 10.44 in the textbook)
                    tree->left = bptr->right;  // T3 is made left sub-tree of A (see Fig. 10.44 in the textbook)
                    bptr->right = tree;              // A is made right sub-tree of C (see Fig. 10.44 in the textbook)
                    if (bptr->balance == 1)
                        tree->balance = -1;
                    else
                        tree->balance = 0;
                    if (bptr->balance == -1)
                        aptr->balance = 1;
                    else
                        aptr->balance = 0;
                    bptr->balance = 0;
                    tree = bptr; // C moved up to the A-place (see Fig. 10.44 in the textbook)
                }
                *ht_inc = FALSE; //re-balancing is done
            }
        }
    }
    else if (data > tree->data)
    {
        // Insert in the right sub-tree
        tree->right = insert(data, tree->right, ht_inc);
        if (*ht_inc == TRUE) // a re-balancing might be needed
        {
            // Check the balance factor after the insertion
            switch (tree->balance)
            {
            case 1: /* Left heavy */
                // the node was left heavy and after insertion has become balanced.
                tree->balance = 0;
                *ht_inc = FALSE; // re-balancing will not be needed at a hihger level
                break;
            case 0: /* Balanced */
                // the node was balanced and after insertion has become right heavy.
                tree->balance = -1;
                break;
            case -1: /* Right heavy */
                // the node was right heavy and after insertion has become an unbalanced sub-tree.
                // Rebalancing rotation is needed - determine the type of rotation
                aptr = tree->right; // "tree" is A and "aptr" is B (see Fig. 10.44 and 10.46 in the textbook)
                if (aptr->balance == -1)
                {
                    printf("Right to Right Rotation\n");
                    tree->right = aptr->left; // T2 is made right sub-tree of A (see Fig. 10.42 in the textbook)
                    aptr->left = tree;              // A is made left sub-tree of B (see Fig. 10.42 in the textbook)
                    tree->balance = 0;
                    aptr->balance = 0;
                    tree = aptr; // B is moved up to A-palce (see slide 47)
                }
                else
                {
                    printf("Right to Left Rotation\n");
                    bptr = aptr->left;              //  "bptr" is C (see Fig. 10.46 in the textbook)
                    aptr->left = bptr->right; // T3 is made left sub-tree of B (see Fig. 10.46 in the textbook)
                    bptr->right = aptr;             // B is made right sub-tree of C (see Fig. 10.46 in the textbook)
                    tree->right = bptr->left;  // T2 is made right sub-tree of A (see Fig. 10.46 in the textbook)
                    bptr->left = tree;
                    if (bptr->balance == -1)
                        tree->balance = 1;
                    else
                        tree->balance = 0;
                    if (bptr->balance == 1)
                        aptr->balance = -1;
                    else
                        aptr->balance = 0;
                    bptr->balance = 0;
                    tree = bptr; // C is moved up to A-palce (see Fig. 10.46 in the textbook)
                }               /*End of else*/
                *ht_inc = FALSE; // re-balancing is done
            }
        }
    }
    return (tree);
}

// A function to display an AVL tree.
void display(struct node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("-");
        printf("%d<%d>", ptr->data,ptr->balance);
        display(ptr->left, level + 1);
    }
}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("% d", ptr->data);
        inorder(ptr->right);
    }
}

struct node *findLargestElement(struct node *tree){
    struct node *current = tree;
    while (current->right != NULL)
        current = current->right;
    return current;
}

struct node *delete(int data, struct node *tree, bool *ht_inc) {
    struct node *aptr, *bptr;

    if (tree == NULL) {
        puts("Does not exist");
        *ht_inc = FALSE;
        return NULL;
    }

    if (data > tree->data) {
        tree->right = delete(data, tree->right, ht_inc);
        if (*ht_inc == TRUE)
            tree->balance++;
    }
    else if (data < tree->data) {
        tree->left = delete(data, tree->left, ht_inc);
        if (*ht_inc == TRUE)
            tree->balance--;
    }
    else {
        if (tree->left == NULL) {
            struct node *tmp = tree->right;
            free(tree);
            *ht_inc = TRUE;
            return tmp;
        }
        else if (tree->right == NULL) {
            struct node *tmp = tree->left;
            free(tree);
            *ht_inc = TRUE;
            return tmp;
        }
        else {
            struct node *temp = findLargestElement(tree->left);
            tree->data = temp->data;
            tree->left = delete(tree->data, tree->left, ht_inc);
            if (*ht_inc == TRUE)
                tree->balance--;
        }
    }

    // Update balance factor after deletion
    if (*ht_inc == TRUE && tree != NULL) {
        printf("\nRebalanced %d %d\n",tree->data, tree->balance);
        if(tree->balance > 0){
            puts("rebalance left");
            // Rebalance left
            if (tree->left != NULL) {
                aptr = tree->left;
                if (aptr->balance >= 0) {
                    // LL rotation
                    printf("Left to Left Rotation\n");
                    tree->left = aptr->right;
                    aptr->right = tree;
                    tree->balance = 0;
                    aptr->balance = 0;
                    tree = aptr;
                } else if (aptr->balance < 0) {
                    // LR rotation
                    printf("Left to Right rotation\n");
                    bptr = aptr->right;
                    aptr->right = bptr->left;
                    bptr->left = aptr;
                    tree->left = bptr->right;
                    bptr->right = tree;
                    if (bptr->balance == 1)
                        tree->balance = -1;
                    else
                        tree->balance = 0;
                    if (bptr->balance == -1)
                        aptr->balance = 1;
                    else
                        aptr->balance = 0;
                    bptr->balance = 0;
                    tree = bptr;
                }
                *ht_inc = FALSE;
            }
        }
        if(tree->balance < 0){

            puts("rebalance right");
            // Rebalance right
            if (tree->right != NULL) {
                aptr = tree->right;
                if (aptr->balance <= 0) {
                    // RR rotation
                    puts("Right to Right Rotation");
                    tree->right = aptr->left;
                    aptr->left = tree;
                    tree->balance = 0;
                    aptr->balance = 0;
                    tree = aptr;
                } else if (aptr->balance > 0) {
                    // RL rotation
                    puts("Right to Left Rotation");
                    bptr = aptr->left;
                    aptr->left = bptr->right;
                    bptr->right = aptr;
                    tree->right = bptr->left;
                    bptr->left = tree;
                    if (bptr->balance == -1)
                        tree->balance = 1;
                    else
                        tree->balance = 0;
                    if (bptr->balance == 1)
                        aptr->balance = -1;
                    else
                        aptr->balance = 0;
                    bptr->balance = 0;
                    tree = bptr;
                }
                *ht_inc = FALSE;
            }
        }
    }
    return tree;
}
// free tree
int free_tree(struct node *tree){
    if(tree->left != NULL) free_tree(tree->left);
    if(tree->right != NULL) free_tree(tree->right);
    free(tree);
    return 1;
}

int main()
{
    bool ht_inc;
    int data, num;
    struct node *root = NULL;
    while (1)
    {
        printf("0.Delete\n");
        printf("1.Insert\n");
        printf("2.Display\n");
        printf("3.Quit\n");
        printf("Enter your option : ");
        scanf("%d", &num);
        switch (num)
        {
        case 0:
            printf("Enter the value to be deleted : ");
            scanf("%d", &data);
            root = delete(data,root,&ht_inc);
            break;

        case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &data);
            if (search(root, data) == NULL)
                root = insert(data, root, &ht_inc);
            else
                printf("Duplicate value ignored\n");
            break;
        case 2:
            if (root == NULL)
            {
                printf("Tree is empty\n");
                continue;
            }
            printf("Tree is :\n");
            display(root, 1);
            printf("\n\n");
            printf("Inorder Traversal is : ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            free_tree(root); // added free tree function
            exit(1);
        default:
            printf("Wrong option\n");
        }
    }
}
