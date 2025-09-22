/*Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue, 
IsEmpty, Traverse using single linked list.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear= NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Memory allocation has failet!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(){
    return(front == NULL);
}

void enque(int ele){
    struct Node* newNode = createNode(ele);

    if(isEmpty()){
        front = rear = newNode;
    }else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Success: Element %d inserted\n", ele);
}

void deque(){
    if(isEmpty()){
        printf("Queue is Empty! can't delete");
        return;
    }

    struct Node* temp = front;
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }
    free(temp);
    printf("Element deleted\n");
}

void traverse(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    struct Node* current = front;
    while (current !=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void Menu(){
    printf("\nMain Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");
}

void freeQue(){
    while(!isEmpty()){
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }
}

int main(){
    int choice, element;
    while(1){
        Menu();
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:printf("Enter element: ");
               scanf("%d", &element);
               enque(element);
               break;      
        case 2: deque(); break;
        case 3: if(isEmpty()){
                printf("Queue is empty\n");
                }else{
                printf("Queue is not empty\n");
                }break;
        case 4: traverse(); break;
        case 5: printf("Exiting program\n");
            freeQue();
            exit(0);
        default: printf("Invalid Choice!,Enter a valid Choice from the options");

        }
    }
    return 0;
}