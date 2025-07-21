// Read numbers & compare using function call by address
#include <stdio.h>
int compare (int*a , int*b){
    if (*a > *b){
        printf("%d is greater one", *a);
    }
    else if (*a == *b){
        printf("Both are equal values");
    }
    else {
        printf("%d is greater one", *b);
    }
}

int main (){
    int a,b;
    printf("Input 2 numnbers: ");
    scanf("%d %d", &a,&b);
    compare(&a, &b);

    return 0;

}