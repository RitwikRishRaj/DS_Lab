/*Write a program to convert infix expression to postfix expression using stack.
Sample Input:
Enter infix expression: (a+b)/cd-e^f
Sample Output:
Postfix: ab+c/def^-*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return top == -1 ? -1 : stack[top]; }
int isEmpty() { return top == -1; }

int prec(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

int isRA(char op) { return op == '^'; }

void convert(char* in) {
    char out[100];
    int i = 0, j = 0;
    
    while (in[i]) {
        if (isalnum(in[i])) {
            out[j++] = in[i];
        }
        else if (in[i] == '(') {
            push(in[i]);
        }
        else if (in[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                out[j++] = pop();
            }
            pop();
        }
        else {
            while (!isEmpty() && peek() != '(' && 
                   (prec(peek()) > prec(in[i]) ||
                   (prec(peek()) == prec(in[i]) && !isRA(in[i])))) {
                out[j++] = pop();
            }
            push(in[i]);
        }
        i++;
    }
    
    while (!isEmpty()) {
        out[j++] = pop();
    }
    
    out[j] = '\0';
    printf("Postfix: %s\n", out);
}

int main() {
    char in[100];
    printf("Enter infix expression: ");
    scanf("%s", in);
    convert(in);
    return 0;
}