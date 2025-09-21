//Write a program to create a circular linked list and display the elements of the list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself initially
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;
    
    printf("Enter no.of nodes: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Enter info of node%d: ", i);
        scanf("%d", &data);
        insert(&head, data);
    }
    
    // Display the list
    display(head);
    
    return 0;
}