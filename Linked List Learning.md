A linked list is a fundamental data structure in C that consists of a sequence of nodes, where each node contains data and a pointer to the next node in the sequence. Unlike an array, a linked list does not store elements in contiguous memory locations, making it dynamic and flexible. This means you can add or remove elements easily without needing to resize or shift the entire structure.

### Node Structure

To create a linked list, you first need to define the structure of a single **node**. A node is a self-referential structure because it contains a pointer to the same type of structure. For Turbo C, you would define this using the `struct` keyword.

```c
struct node {
    int data; // Can be any data type
    struct node *next;
};
```

  * `data`: This field holds the actual data you want to store. It can be an `int`, `char`, `float`, or even another structure.
  * `next`: This is a pointer to the next node in the list. It links one node to the next. The last node's `next` pointer is always `NULL` to signify the end of the list.

### Basic Operations

A linked list typically starts with a **head** pointer, which points to the first node of the list. If the list is empty, the `head` pointer is `NULL`.

#### 1\. Creating a Linked List

You can create a new node and link it to the existing list. For Turbo C, the process involves allocating memory using `malloc` and then assigning values.

```c
#include <stdio.h>
#include <stdlib.h> // For malloc

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    // Allocate 3 nodes in the heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // Assign data and link nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL; // Last node, so next is NULL

    return 0;
}
```

This code creates a simple linked list with three nodes. The `->` operator is used to access members of a structure through a pointer.

#### 2\. Traversing the List

To access the elements of a linked list, you must start from the `head` and traverse the list one node at a time until you reach the end (where the `next` pointer is `NULL`).

```c
void printList(struct node *n) {
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

// In main() after creating the list:
// printList(head);
```

The `printList` function takes the head of the list as input. It then iterates through the list, printing the `data` of each node until it reaches the end.

#### 3\. Inserting a Node

You can insert a new node at the beginning, at the end, or in the middle of a linked list.

  * **At the beginning**: Create a new node, point its `next` pointer to the current `head`, and then update the `head` pointer to the new node.

<!-- end list -->

```c
void insertAtBeginning(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// In main():
// insertAtBeginning(&head, 0); // Note the & for passing a pointer
```

  * **At the end**: Traverse the list to find the last node, then make its `next` pointer point to the new node.

<!-- end list -->

```c
void insertAtEnd(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}
```

### Turbo C Compatibility

Turbo C, a very old compiler, had a few quirks to be aware of:

  * **Header files:** You must include `stdlib.h` for `malloc` and `stdio.h` for `printf`.
  * **Memory:** Turbo C runs in a DOS environment with limited memory, so be mindful of memory leaks. Always free the memory you allocate using `free()` when you are done with it. The `malloc()` function in Turbo C returns a `void*` pointer, which is then cast to the correct data type.
  * **Pointers:** Turbo C's pointer handling is a core part of its C implementation, and linked lists are a great way to learn it.

### Example Program

Here is a complete example of a linked list in C that you can compile and run with Turbo C.

```c
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node
struct node {
    int data;
    struct node *next;
};

// Function to print the linked list
void printList(struct node *n) {
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

// Function to insert a new node at the beginning
void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct node *head = NULL;
    
    // Insert 3 nodes at the beginning
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Created linked list is: \n");
    printList(head);

    // Free the memory
    struct node *current = head;
    struct node *temp = NULL;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;

    return 0;
}
```
