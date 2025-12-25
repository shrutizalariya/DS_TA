// Write a program to implement a node structure for singly linked list. Read the data 
// in a node, print the node.
 
#include <stdio.h> 
#include <stdlib.h>  
 
struct node 
{ 
    int info; 
    struct node *link; 
}; 
 
int main() 
{ 
    struct node *first = NULL, *newNode, *save; 
    int choice; 
 
        //struct node * 
       //It converts a void * (generic pointer) into a pointer of type struct node *. 
       //Converts the void * returned by malloc() to (struct node *) 
     
       //malloc 
       //Takes the number of bytes to allocate as an argument. 
       //Returns a void * (a generic pointer). 
       //Dynamically allocates a block of memory during runtime. 
     
       //sizeof(struct node *) 
       //calculates how many bytes are needed. 
 
    do 
    { 
        newNode = (struct node *)malloc(sizeof(struct node)); 
 
        printf("Enter Data: "); 
        scanf("%d", &newNode->info); 
 
        newNode->link = NULL; 
 
        if (first == NULL) 
        { 
            first = save = newNode; 
        } 
        else 
        { 
            save->link = newNode; 
            save = newNode; 
        }
           printf("Do you want to continue? (1 for Yes / 0 for No): "); 
        scanf("%d", &choice); 
 
    } while (choice != 0); 
 
    printf("\nLinked List Elements:\n"); 
    save  = first; 
 
    while (save != NULL) 
    { 
        printf("%d -> ", save->info); 
        save = save->link; 
    } 
    printf("NULL\n"); 
 
    return 0; 
}