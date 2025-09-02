#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isfull() {
    return rear == MAX - 1;
}

int isempty() {
    return front == -1 || front > rear;
}

void enqueue(int data){
    if(isfull()){
        printf("\nQueue Overflow");
        return; // Fixed: Removed return 0 for a void function
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = data;
    printf("\n%d queued into the queue", data); // Fixed: Removed the extra %d
}

void dequeue(){
    if(isempty()){
        printf("\nQueue is empty");
    }
    else{
        int data = queue[front];
        printf("\nDequeued element is %d", data);
        front++;
    }
}

void peek(){
    if(isempty()){
        printf("\nQueue is empty");
    }
    else{
        int data = queue[front];
        printf("\nfront element is %d", data);
    }
}

void display(){
    int i;
    if(isempty()){
        printf("\nQueue is empty");
    }
    else{
        printf("\nThe elements of queue are:");
        for(i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

void main(){
    int ch, data;
    clrscr();
    while(1){
        printf("\n\n Operations for queue");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("\nData to be enqueued:");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default: // Fixed: Moved default case inside the switch block
                printf("\nInvalid choice. Please try again.");
        }
        getch();
    }
}
