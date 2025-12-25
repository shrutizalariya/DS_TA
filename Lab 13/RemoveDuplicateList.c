//WAP to remove duplicate elements from a singly linked list. 

#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int INFO; 
    struct node* LINK; 
}; 
 
struct node* insertAtLast(struct node* FIRST, int val){ 
 
    if(FIRST == NULL){ 
        FIRST = (struct node*)malloc(sizeof(struct node)); 
 
        if(!FIRST){ 
            printf("\n MEMORY ALLOCATION FAILED \n"); 
            return FIRST; 
        } 
         
        FIRST->INFO = val; 
        FIRST->LINK = NULL; 
        return FIRST; 
    } 
 
    struct node* save = FIRST; 
    while(save->LINK !=NULL){ 
        save = save->LINK; 
    } 
 
    save->LINK = (struct node*)malloc(sizeof(struct node)); 
    if(!(save->LINK)){ 
        printf("\n MEMORY ALLOCATION FAILED \n"); 
        return FIRST; 
    } 
 
    save->LINK->INFO = val; 
    save->LINK->LINK = NULL; 
    return FIRST; 
}
void displayNode(struct node* FIRST){ 
    if(FIRST == NULL ){ 
        printf("\nLINKED LIST IS EMPTY\n"); 
        return; 
    } 
     
    printf("\n"); 
    struct node* save = FIRST; 
    while(save!=NULL){ 
        printf("%d ",save->INFO); 
        save = save->LINK; 
    } 
    printf("\n"); 
} 
 
int find(struct node* FIRST, struct node* LAST){ 
    while(FIRST!=LAST){ 
        if(FIRST->INFO == LAST->INFO) return 1; 
        FIRST = FIRST->LINK; 
    } 
    return 0; 
} 
 
void removeDuplicate(struct node* FIRST){ 
    if(FIRST == NULL || FIRST->LINK == NULL) return; 
 
    struct node* save = FIRST; 
     
    while(save->LINK != NULL ){ 
        int numberExists = 0; 
         
        if( find(FIRST,save->LINK) ){ 
            save->LINK = save->LINK->LINK; 
        } 
        else { 
            save = save->LINK; 
        } 
    } 
 
} 
void main(){ 
    struct node *FIRST = NULL; 
    int opr = 0; 
    int val; 
 
    do { 
        printf("Enter number : \n"); 
        scanf("%d",&val); 
         
        FIRST = insertAtLast(FIRST, val); 
         
        printf("Do you want add more? 1)YES  0)NO \n"); 
        scanf("%d",&opr); 
         
    } while(opr); 
     
    printf("Given list :\n"); 
    displayNode(FIRST); 
 
    removeDuplicate(FIRST); 
    printf("Duplicates removed list :\n"); 
    displayNode(FIRST); 
}