#include <stdio.h> 
#include <stdlib.h> 
// Define a Node 
struct Node { 
    int info; 
    struct Node* link; 
}; 
 
// Create a circular linked list 
struct Node* insert(struct Node* first, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->info = data; 
    newNode->link = NULL; 
 
    if (first == NULL) { 
        first = newNode; 
        newNode->link = first; 
    }  
    else { 
        struct Node* temp = first; 
        while (temp->link != first) { 
            temp = temp->link; 
        } 
        temp->link = newNode; 
        newNode->link = first; 
    } 
    return first; 
} 
 
// Function to split the circular linked list 
void splitList(struct Node* first, struct Node** firstHalf, struct Node** secondHalf) 
{ 
    if (first == NULL) return; 
    struct Node* ptr1 = first; 
    struct Node* ptr2 = first; 
 
    // Use slow and fast pointer to find mid 
    while (ptr2->link != first && ptr2->link->link != first) { 
        ptr1 = ptr1->link; 
        ptr2 = ptr2->link->link; 
    }
    // For even number of nodes 
    if (ptr2->link->link == first) { 
        ptr2 = ptr2->link; 
    } 
 
    // Set the heads 
    *firstHalf = first; 
    if (first->link != first) { 
        *secondHalf = ptr1->link; 
    } 
 
    // Make the first half circular 
    ptr1->link = *firstHalf; 
 
    // Make the second half circular 
    ptr2->link = *secondHalf; 
} 
 
// Function to print the circular linked list 
void printList(struct Node* first) { 
    if (first == NULL) return; 
 
    struct Node* current = first; 
    do { 
        printf("%d -> ", current->info); 
        current = current->link; 
    } while (current != first); 
    printf("\n"); 
} 
 
int main() { 
    struct Node* first = NULL; 
    struct Node *firstHalf = NULL, *secondHalf = NULL; 
    int n, data, i; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    printf("Enter %d elements:\n", n); 
    for (i = 0; i < n; i++) { 
        scanf("%d", &data); 
        first = insert(first, data); 
    } 
    printf("Original Circular Linked List:\n"); 
    printList(first); 
    splitList(first, &firstHalf, &secondHalf); 
    printf("First Half:\n"); 
    printList(firstHalf); 
    printf("Second Half:\n"); 
    printList(secondHalf); 
    return 0; 
}