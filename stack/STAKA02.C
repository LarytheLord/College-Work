#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Max 5

int stack[Max];
int top = -1;

int isfull(){
    return top == Max - 1;
}

int isempty(){
    return top == -1;
}

void push(int data){
    if(isfull()){
        printf("\nStack Overflow!");
    }
    else{
        top++;
        stack[top] = data;
        printf("\n%d is inserted into the stack", data);
    }
}

int pop(){
    if(isempty()){
        printf("\nStack is Empty!");
        return -1;
    }
    else{
        int data = stack[top];
        printf("\n%d popped out of the Stack", data);
        top--;
        return data;
    }
}

int peek(){
    if(isempty()){
        printf("\nStack is Empty, cannot peek.");
        return -1;
    }
    else{
        int data = stack[top];
        printf("\nThe top element is %d", data);
        return data;
    }
}

void display(){
    int i;
    if(isempty()){
        printf("\nStack is empty.");
    }
    else{
        printf("\nStack elements (Top to Bottom):\n");
        for(i = top; i >= 0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

void main(){
    int ch, data, popped_val;
    clrscr();
    while(1){
        printf("\n\n--- Stack Operations ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("\nEnter the element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                popped_val = pop();
                if(popped_val != -1){
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
        getch();
    }
}
