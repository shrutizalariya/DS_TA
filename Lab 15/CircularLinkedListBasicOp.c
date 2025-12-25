#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
 
struct Node { 
    int info; 
    struct Node* link; 
}; 
 
struct Node* first = NULL; 
struct Node* last = NULL; 
 
// Insert at front 
void insertAtFront(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->info = data; 
 
    if (first == NULL) { 
        newNode->link = newNode; 
        first = last = newNode; 
    } else { 
        newNode->link = first; 
        last->link = newNode; 
        first = newNode; 
    } 
}     
// Insert at end 
void insertAtEnd(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->info = data; 
 
    if (first == NULL) { 
        newNode->link = newNode; 
        first = last = newNode; 
    } else { 
        newNode->link = first; 
        last->link = newNode; 
        last = newNode; 
    } 
}

// Insert in sorted order 
void insertAtOrder(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->info = data; 
 
    if (first == NULL) { 
        newNode->link = newNode; 
        first = last = newNode; 
        return; 
    } 
 
    if (data <= first->info) { 
        newNode->link = first; 
        last->link = newNode; 
        first = newNode; 
        return; 
    } 
 
    struct Node* save = first; 
    while (save != last && data >= save->link->info) { 
        save = save->link; 
    } 
 
    newNode->link = save->link; 
    save->link = newNode; 
 
    if (save == last) { 
        last = newNode; 
    } 
} 
 
// Delete node by value  
void deleteAtPosition(int value) { 
    if (first == NULL) 
        return; 
 
    struct Node* pred = first; 
    struct Node* save = first->link; 
// If only one node and it's to be deleted 
    if (first == last && first->info == value) { 
        free(first); 
        first = last = NULL; 
        return; 
    } 
 
// If the node to delete is the first 
    if (first->info == value) { 
        last->link = first->link; 
        struct Node* temp = first; 
        first = first->link; 
        free(temp); 
        return; 
    } 
 
// Traverse to find the node to delete 
    while (save != first && save->info != value) { 
        pred = save; 
        save = save->link; 
    } 
    if (save == first) { 
        printf("Value not found\n"); 
        return; 
    } 
 
    pred->link = save->link; 
    free(save); 
} 
 
// Display all nodes 
void display() { 
    if (first == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node* current = first; 
    do { 
        printf("%d -> ", current->info); 
        current = current->link; 
    } while (current != first); 
    printf("\n"); 
}

int main() { 
    int choice, val; 
    while (flag) { 
        printf("\nEnter:\n"); 
        printf("1. Insert at front\n"); 
        printf("2. Insert at end\n"); 
        printf("3. Insert in order\n"); 
        printf("4. Delete by value\n"); 
        printf("5. Display\n"); 
        printf("6. Exit\n"); 
        printf("Choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
        case 1: 
            printf("Enter value to insert at front: "); 
            scanf("%d", &val); 
            insertAtFront(val); 
            break; 
        case 2: 
            printf("Enter value to insert at end: "); 
            scanf("%d", &val); 
            insertAtEnd(val); 
            break; 
        case 3: 
            printf("Enter value to insert in order: "); 
            scanf("%d", &val); 
            insertAtOrder(val); 
            break; 
        case 4: 
            printf("Enter value to delete: "); 
            scanf("%d", &val); 
            deleteAtPosition(val); 
            break; 
        case 5: 
            display(); 
            break; 
        case 6: 
            printf("Exiting...!"); 
            return 0; 
        default: 
            printf("Invalid option\n"); 
        } 
    } 
    return 0; 
}