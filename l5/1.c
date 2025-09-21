/*Write a program to represent the polynomial equation of single variable using single linked
list and perform the addition of two polynomial equations.*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, power;
    struct Node* next;
};

struct Node* insert(struct Node* poly, int coeff, int power) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    
    if(!poly) return newNode;
    
    struct Node* temp = poly;
    while(temp->next) temp = temp->next;
    temp->next = newNode;
    return poly;
}


void display(struct Node* poly) {
    while(poly) {
        if(poly->power == 0) printf("%d", poly->coeff);
        else printf("%dx^%d", poly->coeff, poly->power);
        
        if(poly->next && poly->next->coeff > 0) printf("+");
        poly = poly->next;
    }
    printf("\n");
}

struct Node* add(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    
    while(p1 && p2) {
        if(p1->power == p2->power) {
            result = insert(result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        } else if(p1->power > p2->power) {
            result = insert(result, p1->coeff, p1->power);
            p1 = p1->next;
        } else {
            result = insert(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }
    
    while(p1) {
        result = insert(result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while(p2) {
        result = insert(result, p2->coeff, p2->power);
        p2 = p2->next;
    }
    
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    int n, coeff, power;
    
    printf("Enter terms in Polynomial 1: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        poly1 = insert(poly1, coeff, power);
    }
    
    printf("Enter terms in Polynomial 2: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        poly2 = insert(poly2, coeff, power);
    }
    
    printf("Polynomial 1: ");
    display(poly1);
    
    printf("Polynomial 2: ");
    display(poly2);
    
    printf("Sum: ");
    display(add(poly1, poly2));
    
    return 0;
}
