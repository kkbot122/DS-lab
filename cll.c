#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; 
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *temp = *head, *prev = NULL;

    if (temp->data == key && temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    if (temp->data == key) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }

    while (temp->next != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    
    printf("Circular Linked List after inserting at the beginning:\n");
    displayList(head);

    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Circular Linked List after inserting at the end:\n");
    displayList(head);

    deleteNode(&head, 20);
    printf("Circular Linked List after deleting a node:\n");
    displayList(head);

    return 0;
}