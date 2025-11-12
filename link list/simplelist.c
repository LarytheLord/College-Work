That's a great request\! Learning linked lists is fundamental. I'll teach you the basics quickly and provide a simple C implementation suitable for Turbo C, **without using complex `struct` definitions** within the nodes themselves, though we must use a `struct` to define the node.

## 🔗 Quick Linked List Overview

A **Linked List** is a linear collection of data elements, called **nodes**, where the order is not given by their physical placement in memory. Instead, each node points to the next node in the sequence.

  * **Node:** The basic building block. It contains:
    1.  **Data:** The information you want to store (e.g., an integer).
    2.  **Pointer (or Link):** A reference/address to the next node in the list.
  * **Head:** A pointer that always points to the **first node** of the list. If the list is empty, the head pointer is `NULL`.

| Head $\rightarrow$ | Data: 10 | Pointer $\rightarrow$ | Data: 20 | Pointer $\rightarrow$ | Data: 30 | Pointer $\rightarrow$ | NULL |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |

-----

## 💻 Simple C Code for Turbo C

Since Turbo C is an older compiler, we'll stick to basic standard C features and include the necessary headers.

The core concept is defining the `struct` for the node and then using functions to manage the list, like inserting a new node at the **front** (or head) of the list and displaying the list.

```c
#include <stdio.h>
#include <stdlib.h> // Required for malloc()

// Define the structure for a single node.
// This is the simplest structure needed for a linked list.
struct Node {
    int data;          // Data field (simple integer)
    struct Node *next; // Pointer to the next Node in the list
};

// Global pointer to the first node (the Head).
// Initialized to NULL, meaning the list is initially empty.
struct Node *head = NULL;

// Function to insert a new node at the beginning of the list (Head).
void insert_at_head(int new_data) {
    // 1. Allocate memory for the new node.
    // (In Turbo C, you must cast the result of malloc)
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation failed (unlikely but good practice)
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // 2. Put the data into the new node.
    new_node->data = new_data;

    // 3. Set the 'next' pointer of the new node to point
    //    to the current head (the old first node).
    new_node->next = head;

    // 4. Move the 'head' pointer to point to the new node,
    //    making it the new first node.
    head = new_node;
}

// Function to display the linked list contents.
void display_list() {
    // Start from the head.
    struct Node *current = head;

    printf("Linked List: ");

    // Traverse the list until 'current' becomes NULL (end of the list).
    while (current != NULL) {
        printf("%d -> ", current->data);
        // Move to the next node.
        current = current->next;
    }
    printf("NULL\n"); // NULL signifies the end of the list.
}

int main() {
    // 1. Insert 10. List: 10 -> NULL
    insert_at_head(10);
    display_list();

    // 2. Insert 20. List: 20 -> 10 -> NULL (20 is the new head)
    insert_at_head(20);
    display_list();

    // 3. Insert 30. List: 30 -> 20 -> 10 -> NULL (30 is the new head)
    insert_at_head(30);
    display_list();

    // Note: In real-world code, you would need a function to
    // free the memory (e.g., a function to delete the list).

    return 0;
}
```

### Key Concepts in the Code

1.  **Node Definition:** `struct Node { int data; struct Node *next; };`
      * The `next` member is a **self-referential structure**, meaning a structure contains a pointer to the same type of structure. This is what links the nodes together.
2.  **Insertion Logic (Step 3 & 4):**
      * `new_node->next = head;` makes the new node point to what was previously the first node.
      * `head = new_node;` updates the list's entry point to the new node. This is crucial for *prepending* data.
3.  **Traversal:** The `display_list` function uses a temporary pointer (`current`) starting at `head` and moves it along (`current = current->next;`) until it hits `NULL`, demonstrating how to visit every node.

Would you like to see how to implement another simple operation, like **deleting the first node**?
