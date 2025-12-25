// Write a menu driven program to implement following operations on the circular linked 
// list.  
// • Insert a node at the front of the linked list.  
// • Delete a node from specified position.  
// • Insert a node at the end of the linked list.  
// • Display all nodes.  
 
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int info; 
    struct Node* lptr; // Pointer to the previous node 
    struct Node* rptr; // Pointer to the next node 
}; 
 
struct Node* l = NULL; // Leftmost (first) node 
struct Node* r = NULL; // Rightmost (last) node 
 
// Function to create a new node 
struct Node* createNode(int x) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->info = x; 
    newNode->lptr = NULL; 
    newNode->rptr = NULL; 
    return newNode; 
} 
 
// Insert a node at the front 
void insertFront(int x) { 
    struct Node* newNode = createNode(x); 
 
    if (l == NULL) { 
        l = r = newNode; 
    } else { 
        newNode->rptr = l; 
        l->lptr = newNode; 
        l = newNode; 
    } 
    printf("Node inserted at front.\n"); 
}
// Insert a node at the end 
void insertEnd(int x) { 
    struct Node* newNode = createNode(x); 
 
    if (r == NULL) { 
        l = r = newNode; 
    } else { 
        r->rptr = newNode; 
        newNode->lptr = r; 
        r = newNode; 
    } 
    printf("Node inserted at end.\n"); 
} 
 
// Delete node from a given position 
void deleteAtPosition(int pos) { 
    if (l == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
 
    struct Node* save = l; 
    int count = 1; 
 
    // Traverse to the desired position 
    while (save != NULL && count < pos) { 
        save = save->rptr; 
        count++; 
    } 
 
    //After complete traversing, say we get save null means the value is invalid, there is no such value 
    if (save == NULL) { 
        printf("Invalid position.\n"); 
        return; 
    } 
 
    // Deleting the first node 
    if (save == l) { 
        l = l->rptr; 
        if (l != NULL) { 
            l->lptr = NULL; 
        } else { 
            r = NULL; //List is emptied here 
        } 
    }
    // Deleting the last node 
    else if (save == r) { 
        r = r->lptr; 
        if (r != NULL) { 
            r->rptr = NULL; 
        } else { 
            l = NULL; // After deletion, if link is empty then pointers are set null here 
        } 
    } 
    // Deleting a node in the middle 
    else { 
        save->lptr->rptr = save->rptr; 
        save->rptr->lptr = save->lptr; 
    } 
 
    free(save); 
    printf("Node deleted from position %d.\n", pos); 
} 
 
// Display the list 
void displayList() { 
    if (l == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
 
    struct Node* save = l; 
    printf("Doubly Linked List: "); 
    while (save != NULL) { 
        printf("%d ", save->info); 
        save = save->rptr; 
    } 
    printf("\n"); 
}
int main() { 
    int choice, data, pos; 
 
    while (choice != 5){ 
        printf("\n----- Doubly Linked List Menu -----\n"); 
        printf("1. Insert node at front\n"); 
        printf("2. Insert node at end\n"); 
        printf("3. Delete node at position\n"); 
        printf("4. Display all nodes\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to insert at front: "); 
                scanf("%d", &data); 
                insertFront(data); 
                break; 
            case 2: 
                printf("Enter data to insert at end: "); 
                scanf("%d", &data); 
                insertEnd(data); 
                break; 
            case 3: 
                printf("Enter position to delete: "); 
                scanf("%d", &pos); 
                deleteAtPosition(pos); 
                break; 
            case 4: 
                displayList(); 
                break; 
            case 5: 
                printf("Exiting program.\n"); 
                break; 
            default: 
                printf("Invalid choice.\n"); 
        } 
 
    } 
    return 0; 
}