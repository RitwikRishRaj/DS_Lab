/*Crete a 1 D array of n elements[use ptr to array]
perform operations using switch case
a) Insert at specific postiton
b) Linear search an element
c) Traverse the array
d) Delete the element from the array*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, choice, pos, i, elem, found = 0;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    do {
        printf("\nWhich operation u want to perform:\n");
        printf("1. Insert at specific position\n");
        printf("2. Linear search an element\n");
        printf("3. Traverse the array\n");
        printf("4. Delete an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter position to insert (1 to %d): ", n+1);
                scanf("%d", &pos);
                if(pos < 1 || pos > n+1) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                arr = (int*)realloc(arr, (n+1) * sizeof(int));
                for(i = n; i >= pos; i--) {
                    arr[i] = arr[i-1];
                }
                arr[pos-1] = elem;
                n++;
                printf("Element inserted.\n");
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &elem);
                found = 0;
                for(i = 0; i < n; i++) {
                    if(arr[i] == elem) {
                        printf("Element found at position %d\n", i+1);
                        found = 1;
                        break;
                    }
                }
                if(!found)
                    printf("Element not found.\n");
                break;

            case 3:
                printf("Array elements: ");
                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if(pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                for(i = pos-1; i < n-1; i++) {
                    arr[i] = arr[i+1];
                }
                n--;
                arr = (int*)realloc(arr, n * sizeof(int));
                printf("Element deleted.\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);

    free(arr);
    return 0;
}