// Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations.
// Sample Input/Output:
// Enter the size of Queue: 5
// Main Menu
// 1. Enqueue
// 2. Dequeue
// 3. IsEmpty
// 4. IsFull
// 5. Traverse
// 6. Exit
// Enter option: 1
// Enter element: 15
// Enter option: 1
// Enter element: 23
// Enter option: 1
// Enter element: 40
// Enter option: 5
// Queue: 15 23 40
// Enter option: 2
// Element deleted
// Enter option: 5
// Queue: 23 40

// #include <stdio.h>
// #include <stdlib.h>

// // Global variables for queue
// int *queue;
// int front = -1, rear = -1, size;

// // Function to check if queue is empty
// int isEmpty() {
//     return (front == -1);
// }

// // Function to check if queue is full
// int isFull() {
//     return (rear == size - 1);
// }

// // Function to add element to queue (Enqueue)
// void enqueue(int element) {
//     if (isFull()) {
//         printf("Queue is full! Cannot insert element.\n");
//         return;
//     }
    
//     if (isEmpty()) {
//         front = 0;  // Initialize front when first element is added
//     }
    
//     rear++;
//     queue[rear] = element;
//     printf("Element %d inserted successfully.\n", element);
// }

// // Function to remove element from queue (Dequeue)
// void dequeue() {
//     if (isEmpty()) {
//         printf("Queue is empty! Cannot delete element.\n");
//         return;
//     }
    
//     printf("Element deleted\n");
    
//     // If only one element was present
//     if (front == rear) {
//         front = rear = -1;
//     } else {
//         front++;
//     }
// }

// // Function to display all elements in queue (Traverse)
// void traverse() {
//     if (isEmpty()) {
//         printf("Queue is empty!\n");
//         return;
//     }
    
//     printf("Queue: ");
//     for (int i = front; i <= rear; i++) {
//         printf("%d ", queue[i]);
//     }
//     printf("\n");
// }

// // Function to display menu
// void displayMenu() {
//     printf("\nMain Menu\n");
//     printf("1. Enqueue\n");
//     printf("2. Dequeue\n");
//     printf("3. IsEmpty\n");
//     printf("4. IsFull\n");
//     printf("5. Traverse\n");
//     printf("6. Exit\n");
// }

// int main() {
//     int choice, element;
    
//     // Get queue size from user
//     printf("Enter the size of Queue: ");
//     scanf("%d", &size);
    
//     // Allocate memory for queue
//     queue = (int*)malloc(size * sizeof(int));
    
//     if (queue == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }
    
//     while (1) {
//         displayMenu();
//         printf("Enter option: ");
//         scanf("%d", &choice);
        
//         switch (choice) {
//             case 1:
//                 printf("Enter element: ");
//                 scanf("%d", &element);
//                 enqueue(element);
//                 break;
                
//             case 2:
//                 dequeue();
//                 break;
                
//             case 3:
//                 if (isEmpty()) {
//                     printf("Queue is empty\n");
//                 } else {
//                     printf("Queue is not empty\n");
//                 }
//                 break;
                
//             case 4:
//                 if (isFull()) {
//                     printf("Queue is full\n");
//                 } else {
//                     printf("Queue is not full\n");
//                 }
//                 break;
                
//             case 5:
//                 traverse();
//                 break;
                
//             case 6:
//                 printf("Exiting program...\n");
//                 free(queue);  // Free allocated memory
//                 exit(0);
                
//             default:
//                 printf("Invalid choice! Please enter a valid option.\n");
//         }
//     }
    
//     return 0;
// }


// Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue, IsEmpty, Traverse using single linked list.
// Sample Input/Output:
// Main Menu
// 1. Enqueue
// 2. Dequeue
// 3. IsEmpty
// 4. Traverse
// 5. Exit
// Enter option: 1
// Enter element: 55
// Enter option: 1
// Enter element: 23
// Enter option: 1
// Enter element: 46
// Enter option: 4
// Queue: 55 23 46
// Enter option: 2
// Element deleted
// Enter option: 4
// Queue: 23 46

// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Global pointers for front and rear of queue
// struct Node* front = NULL;
// struct Node* rear = NULL;

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed!\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to check if queue is empty
// int isEmpty() {
//     return (front == NULL);
// }

// // Function to add element to queue (Enqueue)
// void enqueue(int element) {
//     struct Node* newNode = createNode(element);
    
//     // If queue is empty, both front and rear point to new node
//     if (isEmpty()) {
//         front = rear = newNode;
//     } else {
//         // Add new node at rear and update rear pointer
//         rear->next = newNode;
//         rear = newNode;
//     }
    
//     printf("Element %d inserted successfully.\n", element);
// }

// // Function to remove element from queue (Dequeue)
// void dequeue() {
//     if (isEmpty()) {
//         printf("Queue is empty! Cannot delete element.\n");
//         return;
//     }
    
//     struct Node* temp = front;
    
//     // If only one element is present
//     if (front == rear) {
//         front = rear = NULL;
//     } else {
//         front = front->next;
//     }
    
//     free(temp);
//     printf("Element deleted\n");
// }

// // Function to display all elements in queue (Traverse)
// void traverse() {
//     if (isEmpty()) {
//         printf("Queue is empty!\n");
//         return;
//     }
    
//     printf("Queue: ");
//     struct Node* current = front;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// // Function to display menu
// void displayMenu() {
//     printf("\nMain Menu\n");
//     printf("1. Enqueue\n");
//     printf("2. Dequeue\n");
//     printf("3. IsEmpty\n");
//     printf("4. Traverse\n");
//     printf("5. Exit\n");
// }

// // Function to free all remaining nodes in queue
// void freeQueue() {
//     while (!isEmpty()) {
//         struct Node* temp = front;
//         front = front->next;
//         free(temp);
//     }
// }

// int main() {
//     int choice, element;
    
//     while (1) {
//         displayMenu();
//         printf("Enter option: ");
//         scanf("%d", &choice);
        
//         switch (choice) {
//             case 1:
//                 printf("Enter element: ");
//                 scanf("%d", &element);
//                 enqueue(element);
//                 break;
                
//             case 2:
//                 dequeue();
//                 break;
                
//             case 3:
//                 if (isEmpty()) {
//                     printf("Queue is empty\n");
//                 } else {
//                     printf("Queue is not empty\n");
//                 }
//                 break;
                
//             case 4:
//                 traverse();
//                 break;
                
//             case 5:
//                 printf("Exiting program...\n");
//                 freeQueue();  // Free all remaining nodes
//                 exit(0);
                
//             default:
//                 printf("Invalid choice! Please enter a valid option.\n");
//         }
//     }
    
//     return 0;
// }

// Write a menu driven program to implement circular queue operations such as 
// Enqueue, Dequeue, Traverse, IsEmpty, IsFull using array.
// Sample Input/Output:
// Enter Queue size: 3
// Main Menu
// 1. Enqueue
// 2. Dequeue
// 3. IsEmpty
// 4. IsFull
// 5. Traverse
// 6. Exit
// Enter option: 1
// Enter element: 25
// Enter option: 1
// Enter element: 36
// Enter option: 1
// Enter element: 42
// Enter option: 5
// CQueue: 25 36 42
// Enter option: 2
// Element deleted
// Enter option: 5
// CQueue: 36 42
// Enter option: 2
// Element deleted
// Enter option: 5
// CQueue: 42
// Enter option: 3
// Queue Empty: False

// #include <stdio.h>
// #include <stdlib.h>

// // Global variables for circular queue
// int *queue;
// int front = -1, rear = -1, size;

// // Function to check if queue is empty
// int isEmpty() {
//     return (front == -1);
// }

// // Function to check if queue is full
// int isFull() {
//     return ((rear + 1) % size == front);
// }

// // Function to add element to circular queue (Enqueue)
// void enqueue(int element) {
//     if (isFull()) {
//         printf("Queue is full! Cannot insert element.\n");
//         return;
//     }
    
//     if (isEmpty()) {
//         front = rear = 0;  // Initialize both front and rear when first element is added
//     } else {
//         rear = (rear + 1) % size;  // Circular increment
//     }
    
//     queue[rear] = element;
//     printf("Element %d inserted successfully.\n", element);
// }

// // Function to remove element from circular queue (Dequeue)
// void dequeue() {
//     if (isEmpty()) {
//         printf("Queue is empty! Cannot delete element.\n");
//         return;
//     }
    
//     printf("Element deleted\n");
    
//     // If only one element was present
//     if (front == rear) {
//         front = rear = -1;
//     } else {
//         front = (front + 1) % size;  // Circular increment
//     }
// }

// // Function to display all elements in circular queue (Traverse)
// void traverse() {
//     if (isEmpty()) {
//         printf("CQueue is empty!\n");
//         return;
//     }
    
//     printf("CQueue: ");
//     int i = front;
    
//     // Traverse from front to rear in circular manner
//     while (1) {
//         printf("%d ", queue[i]);
//         if (i == rear) break;  // Stop when we reach rear
//         i = (i + 1) % size;    // Circular increment
//     }
//     printf("\n");
// }

// // Function to display menu
// void displayMenu() {
//     printf("\nMain Menu\n");
//     printf("1. Enqueue\n");
//     printf("2. Dequeue\n");
//     printf("3. IsEmpty\n");
//     printf("4. IsFull\n");
//     printf("5. Traverse\n");
//     printf("6. Exit\n");
// }

// int main() {
//     int choice, element;
    
//     // Get queue size from user
//     printf("Enter Queue size: ");
//     scanf("%d", &size);
    
//     // Allocate memory for circular queue
//     queue = (int*)malloc(size * sizeof(int));
    
//     if (queue == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }
    
//     while (1) {
//         displayMenu();
//         printf("Enter option: ");
//         scanf("%d", &choice);
        
//         switch (choice) {
//             case 1:
//                 printf("Enter element: ");
//                 scanf("%d", &element);
//                 enqueue(element);
//                 break;
                
//             case 2:
//                 dequeue();
//                 break;
                
//             case 3:
//                 if (isEmpty()) {
//                     printf("Queue Empty: True\n");
//                 } else {
//                     printf("Queue Empty: False\n");
//                 }
//                 break;
                
//             case 4:
//                 if (isFull()) {
//                     printf("Queue Full: True\n");
//                 } else {
//                     printf("Queue Full: False\n");
//                 }
//                 break;
                
//             case 5:
//                 traverse();
//                 break;
                
//             case 6:
//                 printf("Exiting program...\n");
//                 free(queue);  // Free allocated memory
//                 exit(0);
                
//             default:
//                 printf("Invalid choice! Please enter a valid option.\n");
//         }
//     }
    
//     return 0;
// }