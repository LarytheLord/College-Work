#incl
ude<stdio.h>
#include<conio.h>
#define MAX 5

// Declaring a queue using array
int queue[MAX];
int front = -1, rear = -1,i;

int isFull() {
    if (rear == MAX - 1) {
	return 1;
    }
    return 0;
}

//check queue is empty
int isEmpty() {
    if (front == -1 || front > rear) {
	return 1;
    }
    return 0;
}

// add data to the queue
void enqueue(int value) {
    if (isFull()) {
	printf("Queue is full, cannot enqueue.\n");
    } else {
	if (front == -1) {
	    front = 0;  //moved front
	}
	rear++;
	queue[rear] = value;
	printf("Enqueued: %d\n", value);
    }
}

// to pop data from the queue
void dequeue() {
    if (isEmpty()) {
	printf("Queue is empty, cannot dequeue.\n");
    } else {
	printf("Dequeued: %d\n", queue[front]);
	front++;
    }
}

// Function to display the queue
void display() {
    if (isEmpty()) {
	printf("Queue is empty.\n");
    } else {
	printf("Queue elements: ");
	for (i = front; i <= rear; i++) {
	    printf("%d ", queue[i]);
	}
	printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
	printf("\nMenu:\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter value to enqueue: ");
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
		return 0;
	    default:
		printf("Invalid choice. Try again.\n");
	}
    }
}








