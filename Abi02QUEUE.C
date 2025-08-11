#include <stdio.h>
#define max 5

int front = -1;
int rear = -1;
int Q[max];

void enqueue(int x) {
    if (rear == max - 1) {
        printf("\nOverflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
	Q[rear] = x;
	printf("inseted inside the queue %d \n", x);
    } else {
	rear++;
	Q[rear] = x;
	printf("Inserted in queue %d \n", x);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
	printf("\nEmpty\n");
    } else if (front == rear) {
	printf("Deleted from queue %d\n", Q[front]);
	front = rear = -1;
    } else {
        printf("%d Deleted from queue\n", Q[front]);
        front++;
    }
}

void display() {
int i;
    if (front == -1 && rear == -1) {
        printf("\nQueue is Empty!!\n");
    } else {
        printf("Queue contents: ");
	for (i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is Empty!!\n");
    } else {
        printf("Front element: %d\n", Q[front]);
    }
}

int main() {
    int ch, val;

    do {
        printf("\n-------QUEUE OPERATIONS MENU-------\n");
        printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Peek\n5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    } while (ch != 5);

    return 0;
}
