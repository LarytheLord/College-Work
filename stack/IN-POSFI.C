#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack Functions
void push(char c) {
    if (top == MAX - 1)
        printf("\nStack Overflow");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    else
        return stack[top];
}

// Function to check precedence
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if character is operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Main conversion function
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(' && top != -1)
                postfix[j++] = pop();
            pop(); // remove '('
        }
        else if (isOperator(ch)) {
            while (precedence(peek()) >= precedence(ch) && peek() != '(')
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0'; // Null-terminate
}

// Main function
void main() {
    char infix[100], postfix[100];

    clrscr();
    printf("Enter infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s", postfix);
    getch();
}
