#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Push element into stack
void push() {
    int data;
    printf("Enter element to push: ");
    scanf("%d", &data);

    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", data);
    } else {
        stack[++top] = data;
        printf("%d pushed into the stack.\n", data);
    }
}

// Pop element from stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top--]);
    }
}

// Peek: view top element
void peek() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot peek.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display all elements (Top to Bottom)
void display() {
    int i;
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack (Top to Bottom):\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function (as per Turbo C style)
void main() {
    int ch;
    clrscr();  // Clear screen (Turbo C only)

    while (1) {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        getch();  // Wait for keypress (Turbo C only)
        clrscr(); // Clear screen for next menu
    }
}