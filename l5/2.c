/*WAP in C to create a double linked list and do the following operations,
a) insert and delete and print number of elements traversed
b) rearrange pointers to print even elements from left to right and print odd elements from right to left and print number of elements traversed
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->val = val;
    new->prev = new->next = NULL;
    return new;
}

void show(struct Node* head) {
    printf("List: ");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct Node* add(struct Node* head, int val, int pos, int* count) {
    struct Node* new = createNode(val);
    *count = 0;
    
    if (!head) return new;
    if (pos == 1) {
        new->next = head;
        head->prev = new;
        return new;
    }
    
    struct Node* temp = head;
    int i = 1;
    while (temp->next && i < pos-1) {
        temp = temp->next;
        i++;
        (*count)++;
    }
    
    new->next = temp->next;
    new->prev = temp;
    if (temp->next) temp->next->prev = new;
    temp->next = new;
    
    return head;
}

struct Node* removeNode(struct Node* head, int pos, int* count) {
    if (!head) {
        printf("Empty list!\n");
        *count = 0;
        return head;
    }
    
    *count = 0;
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        free(temp);
        return head;
    }
    
    struct Node* temp = head;
    int i = 1;
    while (temp && i < pos) {
        temp = temp->next;
        i++;
        (*count)++;
    }
    
    if (!temp) {
        printf("Position not found!\n");
        return head;
    }
    
    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    
    return head;
}

void rearrange(struct Node* head) {
    if (!head) {
        printf("Empty list!\n");
        return;
    }
    
    int total = 0;
    
    printf("Even (left-right): ");
    // Count only the actual movements for even numbers
    struct Node* temp = head;
    while (temp) {
        if (temp->val % 2 == 0) {
            printf("%d ", temp->val);
        }
        // Count the movement to next node (except the last one)
        if (temp->next) {
            temp = temp->next;
            total++;
        } else {
            break;
        }
    }
    
    printf("\nOdd (right-left): ");
    //backwards traverse  for odd numbers
    while (temp) {
        if (temp->val % 2 != 0) {
            printf("%d ", temp->val);
        }
        // Count the movement to previous node (except the first one)
        if (temp->prev) {
            temp = temp->prev;
            total++;
        } else {
            break;
        }
    }
    
    printf("\nTotal moves: %d\n", total);
}

int main() {
    struct Node* head = NULL;
    int n, val, moves;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &val);
        head = add(head, val, i+1, &moves);
    }
    
    printf("\nInitial list: ");
    show(head);
    
    int choice, pos;
    while (1) {
        printf("\n1.Add 2.Remove 3.Show 4.Rearrange 5.Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Value and position: ");
                scanf("%d %d", &val, &pos);
                head = add(head, val, pos, &moves);
                printf("Moves: %d\n", moves);
                break;
            case 2:
                printf("Position to remove: ");
                scanf("%d", &pos);
                head = removeNode(head, pos, &moves);
                printf("Moves: %d\n", moves);
                break;
            case 3:
                show(head);
                break;
            case 4:
                rearrange(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}