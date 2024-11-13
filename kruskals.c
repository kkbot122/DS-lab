#include <stdio.h>
#include <stdlib.h>

#define V 5  // Number of vertices in the graph

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    Edge edges[100];
    int edgeCount;
} Graph;

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

void kruskalsMST(Graph* graph) {
    int parent[V], rank[V];
    for (int v = 0; v < V; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    qsort(graph->edges, graph->edgeCount, sizeof(graph->edges[0]), compareEdges);

    printf("Edge \tWeight\n");
    for (int i = 0, e = 0; e < V - 1 && i < graph->edgeCount; i++) {
        Edge nextEdge = graph->edges[i];
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            printf("%d - %d \t%d\n", nextEdge.src, nextEdge.dest, nextEdge.weight);
            unionSets(parent, rank, x, y);
            e++;
        }
    }
}

int main() {
    Graph graph = { .edgeCount = 7 };

    graph.edges[0] = (Edge){0, 1, 2};
    graph.edges[1] = (Edge){0, 3, 6};
    graph.edges[2] = (Edge){1, 2, 3};
    graph.edges[3] = (Edge){1, 3, 8};
    graph.edges[4] = (Edge){1, 4, 5};
    graph.edges[5] = (Edge){2, 4, 7};
    graph.edges[6] = (Edge){3, 4, 9};

    kruskalsMST(&graph);

    return 0;
}