#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Head pointer for the linked list
struct node *head = NULL;

// Function to create a new node
struct node* createnode(int v) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory not allocated");
        exit(1); // Exit on memory allocation failure
    }
    newnode->data = v;
    newnode->next = NULL;
    return newnode;
}

// Insert a node at the beginning of the list
void insertbeg(int v) {
    struct node *newnode = createnode(v);
    newnode->next = head;
    head = newnode;
}

// Display the list
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("\nThe list is empty\n");
        return;
    }
    printf("\nThe list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int val, ch;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                insertbeg(val);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 3);

    return 0;
}
