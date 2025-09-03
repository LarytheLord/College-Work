#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

int isfull() {
    return (rear + 1) % MAX == front;
}

int isempty() {
    return front == -1;
}

void enqueue(int data) {
    if (isfull()) {
        printf("\nCircular Queue is full!");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    cqueue[rear] = data;
    printf("\n%d enqueued to circular queue.", data);
}

void dequeue() {
    if (isempty()) {
        printf("\nCircular Queue is empty!");
        return;
    }
    int data = cqueue[front];
    printf("\n%d dequeued from circular queue.", data);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void peek() {
    if (isempty()) {
        printf("\nCircular Queue is empty, no front element.");
    } else {
        printf("\nFront element is: %d", cqueue[front]);
    }
}
void display() {
    int i;
    if (isempty()) {
        printf("\nCircular Queue is empty.");
    } else {
        printf("\nCircular Queue elements are:\n");
        i = front;
        while (i != rear) {
            printf("%d ", cqueue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", cqueue[i]);
    }
}



void main() {
    int ch, data;
    clrscr();
    while (1) {
        printf("\n\n--- Circular Queue Operations ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the data to enqueue: ");
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
            default:
                printf("\nInvalid choice. Please try again.");
        }
        getch();
    }
}