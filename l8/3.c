/*Write a menu driven program to implement circular queue operations such as 
Enqueue, Dequeue, Traverse, IsEmpty, IsFull using array.*/

#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, size;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % size == front);
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full! Cannot insert element.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;  
    } else {
        rear = (rear + 1) % size;  
    }
    queue[rear] = element;
    printf("Element %d inserted successfully.\n", element);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot delete element.\n");
        return;
    }
    printf("Element deleted\n");
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void traverse() {
    if (isEmpty()) {
        printf("CQueue is empty!\n");
        return;
    }
    printf("CQueue: ");
    int i = front;    
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;  // Stop when we reach rear
        i = (i + 1) % size;    // Circular increment
    }
    printf("\n");
}

void displayMenu() {
    printf("\nMain Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
}

int main() {
    int choice, element;    
    printf("Enter Queue size: ");
    scanf("%d", &size);
    queue = (int*)malloc(size * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }  
    while (1) {
        displayMenu();
        printf("Enter option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                if (isEmpty()) {
                    printf("Queue Empty: True\n");
                } else {
                    printf("Queue Empty: False\n");
                }
                break;
                
            case 4:
                if (isFull()) {
                    printf("Queue Full: True\n");
                } else {
                    printf("Queue Full: False\n");
                }
                break;
                
            case 5:
                traverse();
                break;
                
            case 6:
                printf("Exiting program...\n");
                free(queue);  
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    
    return 0;
}