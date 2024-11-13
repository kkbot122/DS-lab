#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } 
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
    } 
    else {
        struct Node* temp = front;
        printf("%d dequeued from queue\n", front->data);
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } 
    else {
        printf("Front element is %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } 
    else {
        struct Node* temp = front;
        printf("Queue elements are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    peek();
    display();
    return 0;
}