#include <stdio.h>

#define MAX 10  

int graph[MAX][MAX]; 
int visited[MAX];     
int vertexCount = 0;  

int stack[MAX], top = -1;
int queue[MAX], front = 0, rear = -1;


void addEdge(int u, int v) {
    if (u < vertexCount && v < vertexCount) {
        graph[u][v] = 1;
    } else {
        printf("Edge cannot be added; vertex out of bounds.\n");
    }
}

void insertNode() {
    if (vertexCount < MAX) {
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
    
    for (int i = 0; i < vertexCount; i++) {
        graph[node][i] = 0;
        graph[i][node] = 0;
    }
    printf("Node %d deleted.\n", node);
}


void DFS(int startVertex) {
    for (int i = 0; i < vertexCount; i++) {
        visited[i] = 0;
    }

    stack[++top] = startVertex;
    while (top != -1) {
        int currentVertex = stack[top--];
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;

            for (int i = vertexCount - 1; i >= 0; i--) {
                if (graph[currentVertex][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}


void BFS(int startVertex) {
    for (int i = 0; i < vertexCount; i++) {
        visited[i] = 0;
    }

    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertexCount; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, u, v, node;

    printf("Initial graph with 0 vertices.\n");

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("\nInserting two nodes:\n");
    insertNode();
    insertNode();

    printf("\nDeleting node 0:\n");
    deleteNode(0);

    printf("\nDFS traversal starting from vertex 0:\n");
    DFS(0);

    printf("\n\nBFS traversal starting from vertex 0:\n");
    BFS(0);

    return 0;
}