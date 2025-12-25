//Write a program to implement queue using singly linked list. 
 
#include <stdio.h> 
#include <stdlib.h> 
 
struct node 
{ 
    int INFO; 
    struct node *LINK; 
}; 
 
struct node *front = 0; 
struct node *rear = 0; 
 
void enQueue(int x) 
{ 
    struct node *save; 
 
    save = (struct node *)malloc(sizeof(struct node)); 
 
    save->INFO = x; 
    save->LINK = 0; 
 
    if (front == NULL && rear == NULL) 
    { 
        front = rear = save; 
    } 
    else 
    { 
        rear->LINK = save; 
        rear = save; 
    } 
} 
 
void deQueue() 
{ 
    struct node *save; 
    save = front; 
 
    if (front == 0 && rear == 0) 
    { 
        printf("Queue is Empty\n"); 
    }
    else if (front == rear) 
    { 
        front = rear = 0; 
        free(save); 
    } 
    else 
    { 
        front = front->LINK; 
        free(save); 
    } 
} 
 
void peekFront() 
{ 
    if (front == 0 && rear == 0) 
    { 
        printf("Queue is Empty\n"); 
    } 
    else 
    { 
        printf("Front Element of Queue is :%d", front->INFO); 
    } 
} 
 
void peekRear() 
{ 
    if (front == 0 && rear == 0) 
    { 
        printf("Queue is Empty\n"); 
    } 
    else 
    { 
        printf("Rear Element of Queue is :%d", rear->INFO); 
    } 
} 
 
void display() 
{ 
    struct node *save;  
    save = front;
    if (front == 0 && rear == 0) 
    { 
        printf("Queue is Empty\n"); 
    } 
    else 
    { 
        printf("Queue Elements: "); 
        while (save != NULL) 
        { 
            printf("%d -> ", save->INFO); 
            save = save->LINK; 
        } 
        printf("NULL\n"); 
    } 
} 
 
void main() 
{ 
    int choice, value; 
 
    while(1) 
    { 
        printf("\nMenu Driven:\n"); 
        printf("Press 1 For EnQueue Element in Queue\n"); 
        printf("Press 2 For DeQueue Element in Queue\n"); 
        printf("Press 3 For Peek Front Element of Queue\n"); 
        printf("Press 4 For Peek Rear Element of Queue\n"); 
        printf("Press 5 For Display Elements of Queue\n"); 
        printf("Press 6 For Exit\n"); 
         
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) 
        { 
            case 1: 
                printf("Enter value to enqueue: "); 
                scanf("%d", &value); 
                enQueue(value); 
                break; 
                case 2: 
                deQueue(); 
                break; 
    
            case 3: 
                peekFront(); 
                break; 
    
            case 4: 
                peekRear(); 
                break; 
    
            case 5: 
                display(); 
                break; 
    
            case 6: 
                printf("Exiting...\n"); 
                return; 
    
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    }  
} 