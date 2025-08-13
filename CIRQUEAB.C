#include <stdio.h>
#include <conio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1 + SIZE) % SIZE)) {
	printf("Queue is Full!\n");
	return;
    }

    if (front == -1) { // First element
	front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {
	rear = 0;
    } else {
	rear++;
    }

    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Function to delete element from circular queue
void dequeue() {
    if (front == -1) {
	printf("Queue is Empty!\n");
	return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) {
	front = rear = 0;
    } else if (front == SIZE - 1) {
	front = 0;
    } else {
	front++;
    }
}

// Function to display the circular queue
void display() {
    int i;

    if (front == -1) {
	printf("Queue is Empty!\n");
	return;
    }

    printf("Queue elements are: ");

    if(rear >= front) {
	for (i = front; i <= rear; i++)
	    printf("%d ", queue[i]);
    } else{
	for (i = front; i < SIZE; i++)
	    printf("%d ", queue[i]);
	for (i = 0; i <= rear; i++)
	    printf("%d ", queue[i]);

    }

    printf("\n");
}

void main() {
    int choice, value;
    clrscr();  // Clear screen (Turbo C specific)

    while (1) {
	printf("\nCircular Queue Menu\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
	    printf("Enter value to insert: ");
	    scanf("%d", &value);
	    enqueue(value);
	    break;
	case 2:
	    dequeue();
	    break;
	case 3:
	    display();
	    break;
	case 4:
	    exit(0);
	default:
	    printf("Invalid choice!\n");
	}
    }
}
