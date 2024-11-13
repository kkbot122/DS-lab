#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// Function to traverse the list
void traversal(struct node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert a node at the beginning
struct node* insertAtBeginning(struct node *head) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory not allocated.\n");
        return head;
    }
    newNode->data = 5;
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end
struct node* insertAtEnd(struct node *head) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory not allocated.\n");
        return head;
    }
    newNode->data = 6;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;  // If the list is empty, return the new node as the head
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the last node
    }
    temp->next = newNode;  // Link the new node at the end of the list
    return head;  // Return the head of the list
}

// Function to delete a node at a given position
void deleteNodeAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;

    if (position == 0) {
        head = temp->next;
        free(temp);            
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct node* next = temp->next->next;

    free(temp->next);

    temp->next = next;
}

int main() {
    // Allocate memory in heap
    head = (struct node *)malloc(sizeof(struct node));
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 1;
    head->next = head1;

    // Link second and third nodes
    head1->data = 2;
    head1->next = head2;

    // Third node
    head2->data = 3;
    head2->next = NULL;

    // Inserting at the beginning
    head = insertAtBeginning(head);

    // Inserting at the end
    head = insertAtEnd(head);

    // Traversal to check the new list
    traversal(head);

    // Deleting node at position 3
    deleteNodeAtPosition(3);

    printf("List after deletion:\n");
    traversal(head);

    return 0;
}
