/*create a linear queue using Array(static) & perform operation
enqueue, dequeue, IsEmpty & IsFull*/

#include <stdio.h>
#include <stdlib.h>

int *que;
int front = -1, rear = -1, size;

int isEmpty(){
    return (front == -1);
}

int isFull(){
    return (rear == size-1);
}

void enque(int ele){
    if(isFull()){
        printf("Queue is full, can't insert");
        return;
    }

    if(isEmpty()){
        front =0;
    }
    rear++;
    que[rear] = ele;
    printf("success; Element %d inserted.\n", ele);
}

void deque(){
    if(isEmpty()){
        printf("Queue is empty, can't delete");
        return;
    }
    printf("Element deleted\n");
    if (front==rear){
        front = rear = -1; //if 1 element is present. so, to reset
    }
    else{
        front++;
    }
}

void trav(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for(int i = front; i<=rear; i++){
        printf("%d ", que[i]);
    }
    printf("\n");
}

void Menu(){
    printf("\nMenu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
}

int main(){
    int choice, element;
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    que = (int*)malloc(size * sizeof(int));

    if(que == NULL){
        printf("Memory allocation has failed\n");
        return 1;
    }

    while(1){
        Menu();
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice){
            case 1: 
                    printf("Enter element: ");
                    scanf("%d", &element);
                    enque(element);
                    break;
            case 2: deque();break;
            case 3: if(isEmpty()){
                printf("Queue is empty\n");
            }else {
                printf("Queue is not empty\n");
            }
            break;

            case 4: if (isFull()){
                printf("Queue is full\n");
            }else {
                printf("Queue is not full\n");
            }
            break;

            case 5: trav();
            break;

            case 6: printf("Exiting");
                    free(que);
                    exit(0);
            default: printf("Invalid Choice! Please enter a valid option.\n");
        }
    }
    return 0;
}