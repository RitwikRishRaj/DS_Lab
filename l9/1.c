/*Implement Dequeue[double ended queue] (IO/OP restricted) & perform operations: 
Enqueue, deQueue, Peek, IsEmpty, IsFull, using Static Array*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int dequeue[MAX];
int front = -1, rear = -1;

// Check if full
int IsFull(){
    return((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Check if empty
int IsEmpty(){
    return (front == -1);
}

// Peek at front element
int peekFront(){
    if(IsEmpty()){
        printf("Dequeue is Empty!\n");
        return -1;
    }
    return dequeue[front];
}

// Peek at rear element
int peekRear(){
    if(IsEmpty()){
        printf("Dequeue is Empty!\n");
        return -1;
    }
    return dequeue[rear];
}

// Display status
void displayStatus(){
    printf("\nDequeue Status:\n");
    if(IsEmpty()) printf("Status: Empty\n");
    else if(IsFull()) printf("Status: Full\n");
    else printf("Status: Has elements\n");
    printf("Front Index: %d, Rear Index: %d\n", front, rear);
}

// Insert at right end
void insertRight(int val){
    if(IsFull()){
        printf("Dequeue Overflow!\n"); return;
    }
    if (front == -1) front = rear = 0;
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    dequeue[rear] = val;
    printf("Inserted %d at right\n", val);
}

// Insert at left end
void insertLeft(int val){
    if(IsFull()){
        printf("Dequeue Overflow!\n");
        return;
    }
    if(front == -1) front = rear = 0;
    else if (front == 0) front = MAX - 1;
    else front--;
    dequeue[front] = val;
    printf("Inserted %d at left\n", val);
}

// Delete from left end
void deleteLeft(){
    if (IsEmpty()){
        printf("Dequeue Underflow!\n");
        return;
    }
    printf("Deleted element from left: %d\n", dequeue[front]);
    if(front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
}

// Delete from right end
void deleteRight(){
    if(IsEmpty()){
        printf("Dequeue Underflow!\n");
        return;
    }
    printf("Deleted element from right: %d\n", dequeue[rear]);
    if(front == rear) front = rear = -1;
    else if (rear == 0) rear = MAX - 1;
    else rear--;
}

// Display all elements
void display(){
    if(IsEmpty()){
        printf("Dequeue is Empty!\n");
        return;
    }
    int i = front;
    printf("Dequeue elements: ");
    while (1) {
        printf("%d ", dequeue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void inputRestrictedDeque(){
    int choice, val;
    while(1){
        printf("\nInput Restricted Dequeue Menu\n");
        printf("1. Insert at right (Enqueue)\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Peek Front\n");
        printf("5. Peek Rear\n");
        printf("6. Check if Empty\n");
        printf("7. Check if Full\n");
        printf("8. Display\n");
        printf("9. Display Status\n");
        printf("10. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRight(val);
                break;
            case 2: deleteLeft(); break;
            case 3: deleteRight(); break;
            case 4: val = peekFront();
                if(val != -1) printf("Front element: %d\n", val); break;
            case 5:val = peekRear();
                if(val != -1) printf("Rear element: %d\n", val); break;
            case 6: if(IsEmpty()) printf("Dequeue is Empty\n");
                    else printf("Dequeue is NOT Empty\n"); break;
            case 7: if(IsFull()) printf("Dequeue is Full\n");
                    else printf("Dequeue is NOT Full\n"); break;
            case 8: display(); break;
            case 9: displayStatus(); break;
            case 10: return;
            default: printf("Invalid Choice!\n");
        }
    }
}

void outputRestrictedDeque() {
    int choice, val;
    while (1) {
        printf("\nOutput Restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Insert at left\n");
        printf("3. Delete from left (Dequeue)\n");
        printf("4. Peek Front\n");
        printf("5. Peek Rear\n");
        printf("6. Check if Empty\n");
        printf("7. Check if Full\n");
        printf("8. Display\n");
        printf("9. Display Status\n");
        printf("10. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRight(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertLeft(val);
                break;
            case 3: deleteLeft(); break;
            case 4:
                val = peekFront();
                if(val != -1) printf("Front element: %d\n", val); break;
            case 5:
                val = peekRear();
                if(val != -1) printf("Rear element: %d\n", val); break;
            case 6: if(IsEmpty()) printf("Dequeue is Empty\n");
                    else printf("Dequeue is NOT Empty\n"); break;
            case 7: if(IsFull()) printf("Dequeue is Full\n");
                    else printf("Dequeue is NOT Full\n"); break;
            case 8: display(); break;
            case 9: displayStatus(); break;
            case 10: return;
            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    int choice;
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) inputRestrictedDeque();
    else if (choice == 2) outputRestrictedDeque();
    else printf("Invalid choice!\n");
    return 0;
}