#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * link;
};

struct node* front = NULL;
struct node* rear = NULL;

// Enqueue
void enqueue(int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    ptr -> data = value;
    ptr -> link = NULL;

    if(front == NULL && rear == NULL){
        front = rear = ptr;
    }
    else{
        rear->link = ptr;
        rear = ptr;
    }
}

//Dequeue
int dequeue(){
    if(front == NULL){
        printf("underflow\n");
        return -1;
    }
    else{
        struct node* temp = front;
        int temp_data = front ->data;
        front = front->link;
        free(temp);

        return temp_data;
    }
}

void display(struct node* head){
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

int main() {
    
    return 0;
}
