/*WAP to represent the polynomial of single variable using 1-D array and perform the addition
of two polynomial equations.
it can except input like: 5x^-6+3x^3+3 as well
input like:
Poly-1 - Enter number of terms: 3
Enter 3 terms coeff, power:
5 -6
3 3  
3 0

Poly-2 - Enter number of terms: 2
Enter 2 terms coeff, power:
2 3
1 -6
Resultant Poly look like: 5x^2+7x^1+10x^0  */
#include <stdio.h>

struct Term {
    int coeff, power;
};

int main() {
    struct Term p1[20], p2[20], result[40];
    int n1, n2, k = 0;
    
    printf("Polynomial-1 - Enter number of terms: ");
    scanf("%d", &n1);
    printf("Enter %d terms (coeff power):\n", n1);
    for(int i = 0; i < n1; i++) {
        scanf("%d %d", &p1[i].coeff, &p1[i].power);
    }
    
    printf("Polynomial-2 - Enter number of terms: ");
    scanf("%d", &n2);
    printf("Enter %d terms (coeff power):\n", n2);
    for(int i = 0; i < n2; i++) {
        scanf("%d %d", &p2[i].coeff, &p2[i].power);
    }
    
   
    for(int i = 0; i < n1; i++) {
        result[k++] = p1[i];
    }
    
    
    for(int i = 0; i < n2; i++) {
        int found = 0;
        for(int j = 0; j < k; j++) {
            if(p2[i].power == result[j].power) {
                result[j].coeff += p2[i].coeff;
                found = 1;
                break;
            }
        }
        if(!found) {
            result[k++] = p2[i];
        }
    }
    
   
    for(int i = 0; i < k-1; i++) {
        for(int j = i+1; j < k; j++) {
            if(result[i].power < result[j].power) {
                struct Term temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    

    printf("result: ");
    for(int i = 0; i < k; i++) {
        if(result[i].coeff == 0) continue;
        
        if(i > 0 && result[i].coeff > 0) printf("+");
        
        if(result[i].power == 0) 
            printf("%d", result[i].coeff);
        else if(result[i].power == 1) 
            printf("%dx", result[i].coeff);
        else 
            printf("%dx^%d", result[i].coeff, result[i].power);
    }
    printf("\n");
    
    return 0;
}