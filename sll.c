#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void addnode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

void insertAtBeginning(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

void insertAtRandomPosition(int data, int position) {
    int nodeCount = countNodes();

    if (position < 0 || position > nodeCount) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        insertAtBeginning(data);
        return;
    }

    if (position == nodeCount) {
        insertAtEnd(data);
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = data;

    struct node *current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }

    newnode->next = current->next;
    current->next = newnode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

void deleteAtRandomPosition(int position) {
    int nodeCount = countNodes();

    if (position < 0 || position >= nodeCount) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginning();
        return;
    }

    if (position == nodeCount - 1) {
        deleteAtEnd();
        return;
    }

    struct node *current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }

    struct node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

void reverseList() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display() {
    struct node *current = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of singly linked list: \n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int countNodes() {
    int count = 0;
    struct node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    addnode(40);
    addnode(3);
    addnode(4);
    addnode(2);
    addnode(5);

    display();

    int nodeCount = countNodes();
    printf("Number of nodes in the linked list: %d\n", nodeCount);

    insertAtBeginning(10);
    display();

    nodeCount = countNodes();
    printf("Number of nodes in the linked list after insertion at the beginning: %d\n", nodeCount);

    insertAtEnd(20);
    display();

    nodeCount = countNodes();
    printf("Number of nodes in the linked list after insertion at the end: %d\n", nodeCount);

    int pos, value;
    printf("Enter position and value to insert at random position: ");
    scanf("%d %d", &pos, &value);
    insertAtRandomPosition(value, pos);
    display();

    nodeCount = countNodes();
    printf("Number of nodes in the linked list after insertion at random position: %d\n", nodeCount);

    printf("Enter position to delete from the list: ");
    scanf("%d", &pos);
    deleteAtRandomPosition(pos);
    display();

    nodeCount = countNodes();
    printf("Number of nodes in the linked list after deletion at random position: %d\n", nodeCount);

    reverseList();
    printf("Linked list after reversal:\n");
    display();

    return 0;
}