/*Write a menu driven program to create a stack using dynamic array and perform the following operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if (top < MAX - 1) stack[++top] = x;
    else printf("Stack Overflow\n");
}

void pop() {
    if (top >= 0) printf("%d deleted from Stack\n", stack[top--]);
    else printf("Stack Underflow\n");
}

int isEmpty() { return top == -1; }
int isFull() { return top == MAX - 1; }

void traverse() {
    if (isEmpty()) printf("Stack is empty\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, x;
    while (1) {
        printf("Main Menu\n1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter element to be pushed into the stack: ");
                   scanf("%d", &x); push(x); break;
            case 2: pop(); break;
            case 3: printf("Stack empty: %s\n", isEmpty() ? "True" : "False"); break;
            case 4: printf("Stack full: %s\n", isFull() ? "True" : "False"); break;
            case 5: traverse(); break;
            case 6: exit(0);
            default: printf("Invalid option\n");
        }
    }
    return 0;
}