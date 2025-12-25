//WAP to delete alternate nodes of a doubly linked list.  
 
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int info; 
    struct Node* lptr; 
    struct Node* rptr; 
}; 
 
struct Node* l = NULL;  
struct Node* r = NULL;  
 
struct Node* createNode(int x) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->info = x; 
    newNode->lptr = NULL; 
    newNode->rptr = NULL; 
    return newNode; 
} 
 
// Insert at end, (we can also take insert at first) 
void insertEnd(int x) { 
    struct Node* newNode = createNode(x); 
    if (r == NULL) { 
        l = r = newNode; 
    } else { 
        r->rptr = newNode; 
        newNode->lptr = r; 
        r = newNode; 
    } 
}
// Displays the list 
void displayList() { 
    struct Node* save = l; 
    printf("List: "); 
    while (save != NULL) { 
        printf("%d ", save->info); 
        save = save->rptr; 
    } 
    printf("\n"); 
} 
 
// Delete alternate nodes starting from the second 
void deleteAlternate() { 
    if (l == NULL) return; 
 
    struct Node* curr = l; 
    struct Node* nextNode; 
 
    //Loop will go until the curr node is null and its rptr is null 
    while (curr != NULL && curr->rptr != NULL) { 
        nextNode = curr->rptr; 
 
        // Remove nextNode from list 
        curr->rptr = nextNode->rptr; 
        if (nextNode->rptr != NULL) 
            nextNode->rptr->lptr = curr; 
        else 
            r = curr; // If deleted node was last, update r 
 
        free(nextNode); 
        curr = curr->rptr; //we are skipping one node that is why setting curr to 1 step ahead 
    } 
 
    printf("Alternate nodes deleted.\n"); 
}
int main() { 
    int choice, data; 
 
    while (choice != 4){ 
        printf("\n--- Menu ---\n"); 
        printf("1. Insert at end\n"); 
        printf("2. Display list\n"); 
        printf("3. Delete alternate nodes\n"); 
        printf("4. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data: "); 
                scanf("%d", &data); 
                insertEnd(data); 
                break; 
            case 2: 
                displayList(); 
                break; 
            case 3: 
                deleteAlternate(); 
                break; 
            case 4: 
                printf("Exiting.\n"); 
                break; 
            default: 
                printf("Invalid choice.\n"); 
        } 
    } 
    return 0; 
} 
 