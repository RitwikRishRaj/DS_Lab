/*Write a menu driven program to create a stack using linked list and perform the following operation using function
Push
b. Pop
c. IsEmpty
d. display the stack elements*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d deleted from Stack\n", top->data);
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

int isEmpty() {
    return top == NULL;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, x;
    while (1) {
        printf("1. Push\n2. Pop\n3. IsEmpty\n4. Display\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2: 
                pop();
                break;
            case 3: 
                printf("Stack empty: %s\n", isEmpty() ? "True" : "False");
                break;
            case 4: 
                display();
                break;
            case 5: 
                exit(0);
            default: 
                printf("Invalid option\n");
        }
    }
    return 0;
}