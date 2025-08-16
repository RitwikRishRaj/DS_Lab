/*WAP to create a single linked list of 'n' nodes
perform (a) Insert node at start, Last & mid (i have used pos instead coz dk what if no.of elements is even)
        (b) Delete   "       "            "
        (c) Count number of nodes*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *head = NULL;

// display list
void disp() {
    struct Node* t = head;
    printf("List: ");
    while(t) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void insBeg(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = head;
    head = n;
}

void insEnd(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    if(!head) { head = n; return; }
    struct Node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}

void insPos(int x, int pos) {
    if(pos == 1) { insBeg(x); return; }
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    struct Node* t = head;
    for(int i = 1; i < pos-1 && t; i++) t = t->next;
    if(!t) { printf("Invalid pos\n"); free(n); return; }
    n->next = t->next;
    t->next = n;
}

void delPos(int pos) {
    if(!head) { printf("Empty list\n"); return; }
    struct Node* t = head;
    if(pos == 1) { head = t->next; free(t); return; }
    for(int i = 1; i < pos-1 && t; i++) t = t->next;
    if(!t || !t->next) { printf("Invalid pos\n"); return; }
    struct Node* d = t->next;
    t->next = d->next;
    free(d);
}

int count() {
    int c = 0;
    struct Node* t = head;
    while(t) { c++; t = t->next; }
    return c;
}

int main() {
    int n, ch, x, pos, sub;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d data values: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        insEnd(x);
    }

    while(1) {
        printf("\n1.Insert 2.Delete 3.Count 4.Display 5.Exit\nChoice: ");
        if(scanf("%d", &ch) != 1) {
            printf("Invalid input!\n");
            continue;
        }

        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &x);
                printf("1.Beg 2.End 3.Pos\nChoice: ");
                scanf("%d", &sub);
                if(sub == 1) insBeg(x);
                else if(sub == 2) insEnd(x);
                else if(sub == 3) {
                    printf("Enter pos: ");
                    scanf("%d", &pos);
                    insPos(x, pos);
                } else printf("Invalid\n");
                disp();
                break;
            case 2:
                printf("Enter pos to del: ");
                scanf("%d", &pos);
                delPos(pos);
                disp();
                break;
            case 3:
                printf("Total nodes: %d\n", count());
                break;
            case 4:
                disp();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
