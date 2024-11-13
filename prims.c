#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

int selectMinVertex(int value[], int mstSet[]) {
    int min = INT_MAX, vertex = -1;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && value[i] < min) {
            min = value[i];
            vertex = i;
        }
    }
    return vertex;
}

void primsMST(int graph[V][V]) {
    int parent[V];  // Stores MST
    int value[V];   // Used for edge weights
    int mstSet[V];  // MST inclusion status

    for (int i = 0; i < V; i++) {
        value[i] = INT_MAX;
        mstSet[i] = 0;
    }

    value[0] = 0;
    parent[0] = -1;  // Start from the first vertex

    for (int i = 0; i < V - 1; i++) {
        int u = selectMinVertex(value, mstSet);
        mstSet[u] = 1;

        for (int j = 0; j < V; j++) {
            if (graph[u][j] && !mstSet[j] && graph[u][j] < value[j]) {
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    primsMST(graph);

    return 0;
}