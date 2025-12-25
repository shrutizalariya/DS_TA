//Write a program to implement stack using singly linked list.  
 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node{ 
    int INFO; 
    struct node *LINK; 
}; 
 
struct node* top = 0; 
 
void push(int x){ 
    struct node* NEW; 
     
    NEW = (struct node*)malloc(sizeof(struct node)); 
     
    NEW->INFO = x; 
     
    NEW->LINK = top; 
     
    top = NEW; 
} 
 
void pop(){ 
    if (top == 0) 
    { 
        printf("Stack is Empty\n"); 
    } 
    else 
    { 
        struct node* save; 
        save = top; 
        printf("Popped Element is :%d", top->INFO); 
        top = top->LINK; 
        free(save); 
    } 
} 
 
void peek(){ 
    if (top == 0) 
    { 
        printf("Stack is Empty\n"); 
    } 
    else 
    { 
        printf("Top Element is :%d",top->INFO); 
    } 
} 
 
void display(){ 
    if (top == 0) 
    { 
        printf("Stack is Empty\n"); 
    } 
    else 
    { 
        struct node* save; 
        save = top; 
         
        while (save != 0) 
        { 
            printf("%d ",save->INFO); 
            save = save->LINK; 
        } 
    } 
} 
 
void main(){ 
    int choice, value; 
 
    while(1) { 
        printf("\nMenu Driven:\n"); 
        printf("Press 1 For Push Node in Stack\n"); 
        printf("Press 2 For Pop Node in Stack\n"); 
        printf("Press 3 For Peek Node in Stack\n"); 
        printf("Press 4 For Display Node in Stack\n"); 
        printf("Press 5 For Exit Node in Stack\n"); 
        
        printf("Enter your choice: "); 
        scanf("%d", &choice);
        switch (choice) { 
            case 1: 
                printf("Enter value to push: "); 
                scanf("%d", &value); 
                push(value); 
                break; 
    
            case 2: 
                pop(); 
                break; 
    
            case 3: 
                peek(); 
                break; 
    
            case 4: 
                display(); 
                break; 
    
            case 5: 
                printf("Exiting...\n"); 
                return; 
    
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    }     
} 