/*Implement Priority Queue and perform operations such as
Enqueue, Dequeue, traverse using Linked List (Single)*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

void enqueue(int data, int priority){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct node *temp = front;
        while (temp->next != NULL && temp->next->priority <= priority)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d with priority %d\n", data, priority);
}

void dequeue(){
    if(front == NULL){
        printf("Priority Queue Underflow!\n");
        return;
    }
    struct node *temp = front;
    printf("Deleted element: %d (priority %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

void display(){
    if (front == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }
    struct node *temp = front;
    printf("Priority Queue Elements:\n");
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    int choice, data, priority;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
