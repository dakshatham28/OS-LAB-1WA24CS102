#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    int x;
    if(top == MAX-1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    int i;
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        for(i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int ch;

    do {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
        }

    } while(ch != 4);

    return 0;
}


