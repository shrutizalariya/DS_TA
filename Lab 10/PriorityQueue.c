//PRIORITY QUEUE 
#include<stdio.h>

struct priority_q{
    int data;
    int priority;
};

struct priority_q queue[5];

int front = -1;
int rear = -1;

void enqueue(int x, int y){
    if(rear == 4){
        printf("Queue Overflow");
        return;
    }
    rear++;
    queue[rear].data = x;
    queue[rear].priority = y;
    if(front == -1){
        front = 0;
    }
}

void dequeue(){
    if(front == -1){
        printf("Queue Underflow");
        return;
    }
    int max_i = front;
    for(int i = front+1 ; i <= rear ; i++){
        if(queue[i].priority > queue[max_i].priority){
            max_i = i;
        }
    }
    printf("Deleted Element is: { %d : %d }\n", queue[max_i].data, queue[max_i].priority);
    for(int i = max_i; i<=rear ; i++){
        queue[i] = queue[i+1];
    }
    rear--;
}

void display(){
    if(front == -1){
        printf("Queue is Empty");
        return;
    }
    for(int i = front ; i <= rear ; i++){
        printf("{%d : %d}\n", queue[i].data, queue[i].priority);
    }
}

void main(){
    enqueue(10, 5);
    enqueue(20, 3);
    enqueue(30, 7);
    enqueue(20,7);
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
}
 
// #include <stdio.h> 
// #define SIZE 100 
 
// // Define a structure for queue elements 
// struct Element { 
//     int value; 
//     int priority; 
// }; 
 
// struct Element queue[SIZE]; 
// int front = -1, rear = -1; 
 
// // Function to insert an element 
// void insert(int value, int prio) { 
//     if (rear >= SIZE - 1) { 
//         printf("Priority Queue Overflow!\n"); 
//         return; 
//     } 
 
//     if (front == -1) { 
//         front = rear = 0; 
//     } else { 
//         rear++; 
//     } 
 
//     queue[rear].value = value; 
//     queue[rear].priority = prio; 
 
//     printf("Inserted %d with priority %d\n", value, prio); 
// } 
 
// // Function to delete element with highest priority (lowest priority number) 
// void deleteHighestPriority() { 
//     if (front == -1) { 
//         printf("Priority Queue Underflow!\n"); 
//         return; 
//     } 
 
//     int i, pos = front; 
//     for (i = front + 1; i <= rear; i++) { 
//         if (queue[i].priority < queue[pos].priority) { 
//             pos = i; 
//         } 
//     } 
       
//     printf("Deleted %d with priority %d\n", queue[pos].value, queue[pos].priority); 
 
//     for (i = pos; i < rear; i++) { 
//         queue[i] = queue[i + 1]; 
//     } 
 
//     rear--; 
 
//     // If queue becomes empty after deletion 
//     if (rear < front) 
//         front = rear = -1; 
// } 
 
// // Function to display the queue 
// void display() { 
//     if (front == -1) { 
//         printf("Priority Queue is empty.\n"); 
//         return; 
//     } 
 
//     printf("Priority Queue elements:\n"); 
//     int i; 
//     for (i = front; i <= rear; i++) { 
//         printf("Value: %d, Priority: %d\n", queue[i].value, queue[i].priority); 
//     } 
// } 
 
// int main() { 
//     int choice, value, prio; 
 
//     while (1) { 
//         printf("\n--- Priority Queue Menu ---\n"); 
//         printf("1. Insert\n"); 
//         printf("2. Delete Highest Priority\n"); 
//         printf("3. Display\n"); 
//         printf("4. Exit\n"); 
//         printf("Enter your choice: "); 
//         scanf("%d", &choice); 
 
//         switch (choice) { 
//         case 1: 
//             printf("Enter value to insert: "); 
//             scanf("%d", &value); 
//             printf("Enter priority (lower number = higher priority): "); 
//             scanf("%d", &prio); 
//             insert(value, prio); 
//             break;
//         case 2: 
//             deleteHighestPriority(); 
//             break; 
//         case 3: 
//             display(); 
//             break; 
//         case 4: 
//             printf("Exiting program.\n"); 
//             return 0; 
//         default: 
//             printf("Invalid choice! Try again.\n"); 
//             break;
//         } 
//     } 
//     return 0; 
// }