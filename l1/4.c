/*Create a struct to represent complex no. & perform
addition        :call by value
multiplication  :call by address
R - 3 4
I - 4 5
sum  = 7+9i
mult = 12+20i
*/

#include <stdio.h>

struct Complex {
    int real;
    int imag;
};


struct Complex add(struct Complex c1, struct Complex c2) {
    struct Complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
}


void multiply(struct Complex *c1, struct Complex *c2, struct Complex *result) {
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

int main() {
    struct Complex R = {3, 4};  
    struct Complex I = {4, 5};  

    struct Complex sum = add(R, I);
    printf("Sum = %d+%di\n", sum.real, sum.imag);

    struct Complex mult;
    multiply(&R, &I, &mult);
    printf("Multiplication = %d+%di\n", mult.real, mult.imag);

    return 0;
}