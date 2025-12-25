//PRIORITY QUEUE IMPLEMENTATION USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data, int priority){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;
    if(front == NULL){
        new_node->next = NULL;
        front = new_node;
        rear = new_node;
        return;
    }
    if(priority > front->priority){
        new_node->next = front;
        front = new_node;
        return;
    }
    struct node *save = front;
    while(save->next != NULL && save->next->priority > new_node->priority){
        save = save->next;
    }
    new_node->next = save->next;
    save->next = new_node;
    if(new_node->next == NULL){
        rear = new_node;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* save = front;
    front = front->next;
    free(save);
    if(front == NULL){
        rear = NULL;
    }
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* save = front;
    while(save != NULL){
        printf("{%d : %d}", save->data, save->priority);
        save = save->next;
    }
}

void main(){
    enqueue(10, 5);
    enqueue(10, 1);
    enqueue(20, 3);
    enqueue(20, 4);
    display();
}