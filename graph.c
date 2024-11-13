#include <stdio.h>
#include <stdlib.h>

#define MAX 10 


struct Node {
    int vertex;          
    struct Node* next;   
};

struct Node* adjList[MAX];
int visited[MAX];         
int vertexCount = 0;     

struct StackNode {
    int data;            
    struct StackNode* next; 
};

struct StackNode* top = NULL; 

struct QueueNode {
    int data;              
    struct QueueNode* next; 
};

struct QueueNode* front = NULL; 
struct QueueNode* rear = NULL; 


void initializeGraph() {
    for (int i = 0; i < MAX; i++) adjList[i] = NULL;
}


void addEdge(int u, int v) {
    if (u < vertexCount && v < vertexCount) {  
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = v;                  
        newNode->next = adjList[u];           
        adjList[u] = newNode;             
    } else {
        printf("Edge cannot be added; vertex out of bounds.\n");
    }
}

void insertNode() {
    if (vertexCount < MAX) {                  
        adjList[vertexCount] = NULL;       
        vertexCount++;                      
        printf("Node %d added.\n", vertexCount - 1);
    } else {
        printf("Max vertices reached; cannot insert node.\n");
    }
}

void deleteNode(int node) {
    if (node >= vertexCount) {                
        printf("Node %d does not exist.\n", node);
        return;
    }

    struct Node* temp = adjList[node];
    while (temp) {
        struct Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);                        
    }
    adjList[node] = NULL;                   

    for (int i = 0; i < vertexCount; i++) {
        struct Node* prev = NULL;
        struct Node* current = adjList[i];
        while (current) {
            if (current->vertex == node) {    
                if (prev) 
                    prev->next = current->next;  
                else 
                    adjList[i] = current->next;   

                free(current);                  
                break;
            }
            prev = current;
            current = current->next;
        }
    }
    printf("Node %d deleted.\n", node);
}

void push(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;       
    newNode->next = top;        
    top = newNode;             
}

int pop() {
    if (top == NULL) return -1;  
    
    struct StackNode* temp = top;
    int data = temp->data;       
    top = top->next;            
    free(temp);                 
    return data;
}


void DFS(int startVertex) {
    for (int i = 0; i < vertexCount; i++) visited[i] = 0; 

    push(startVertex);  
    
    while (top != NULL) {  
        int currentVertex = pop();  
        
        if (!visited[currentVertex]) {  
            printf("%d ", currentVertex);   
            
            visited[currentVertex] = 1;    

            struct Node* temp = adjList[currentVertex];  
            while (temp) {  
                if (!visited[temp->vertex]) {   
                    push(temp->vertex);      
                }
                temp = temp->next;    
            }
        }
    }
}

void enqueue(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;       
    newNode->next = NULL;       

    if (rear == NULL) {         
        front = rear = newNode;
    } else {
        rear->next = newNode;   // Link old rear to new node and update rear pointer
        rear = newNode;
    }
}

// Function to dequeue a vertex from the queue (for BFS)
int dequeue() {
    if (front == NULL) return -1;  // Return -1 if queue is empty

    struct QueueNode* temp = front;
    int data = temp->data;          // Get the vertex number from front of queue
    
    front = front->next;            // Move front pointer to next node
    
    if (front == NULL) rear = NULL;   // If queue is now empty, update rear as well
    
    free(temp);                     // Free memory of dequeued node
    
    return data;
}

// Breadth-First Search (BFS) using queue
void BFS(int startVertex) {
    for (int i = 0; i < vertexCount; i++) visited[i] = 0;  // Initialize visited array

    enqueue(startVertex);      // Enqueue starting vertex and mark as visited
    visited[startVertex] = 1;

    while (front != NULL) {   // While there are vertices in the queue
        int currentVertex = dequeue();  // Dequeue a vertex from the queue
        
        printf("%d ", currentVertex);   // Print current vertex

        struct Node* temp = adjList[currentVertex];  // Get neighbors
        
        while (temp) {   // Iterate through neighbors 
            if (!visited[temp->vertex]) {   // If neighbor not visited yet 
                enqueue(temp->vertex);      // Enqueue neighbor and mark as visited 
                visited[temp->vertex] = 1;
            }
            temp = temp->next;   // Move to next neighbor 
        }
    }
}

int main() {
    int edges, u, v;

    printf("Initial graph with 0 vertices.\n");

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);   // Add directed edge from u to v 
    }

    printf("\nInserting two nodes:\n");
    
    insertNode();         // Insert first new node 
    insertNode();         // Insert second new node 

    printf("\nDeleting node 0:\n");
    deleteNode(0);       // Delete node 0

    printf("\nDFS traversal starting from vertex 0:\n");
    DFS(0);              // Perform DFS starting from vertex 0

    printf("\n\nBFS traversal starting from vertex 0:\n");
    BFS(0);              // Perform BFS starting from vertex 0

    return 0;
}