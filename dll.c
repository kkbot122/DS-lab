#include <stdio.h>
#include<stdlib.h>

// creating a doubly linked list

struct node {
    int data;
    struct node *prev;
    struct node *next;   
};

struct node* insertAtBeg(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next= head;
    temp->prev=NULL;
    head = temp;
    return head;
}

void printNode(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

struct node* insertAtEnd(struct node* head, int data) {
    struct node* temp = head;
    struct node* ptr4 = (struct node*)malloc(sizeof(struct node));
    ptr4->data = data;
    ptr4->next = NULL;

    if (head == NULL) {
        ptr4->prev = NULL;
        head = ptr4;
        return head;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr4;
    ptr4->prev = temp;

    return head;
}

struct node* insertAtPosition(struct node* head, int data, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return head;
    }

    struct node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    if (temp->next == NULL) {
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}



int main(){
    struct node *ptr1 = (struct node*)malloc(sizeof(struct node));
    struct node *ptr2 = (struct node*)malloc(sizeof(struct node));


    ptr1->data = 1;
    ptr1->prev = NULL;
    ptr1->next = ptr2;


    ptr2 -> data = 2;
    ptr2->next=NULL;
    ptr2->prev=ptr1;

    struct node* head = ptr1;


    head = insertAtBeg(head, 3);
    //printNode(head);

    head = insertAtEnd(head, 5);
    //printNode(head);

    head = insertAtPosition(head, 6, 3);
    printNode(head);
    return 0;
}
