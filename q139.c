/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

// Graph structure
typedef struct {
    int V;
    int E;
    int **adj; // Adjacency matrix (can be changed to adjacency list for efficiency)
    int *weights; // Weights for adjacency list approach, or matrix weights
} Graph;

// Priority Queue Node
typedef struct PQNode {
    int vertex;
    int dist;
    struct PQNode *next;
} PQNode;

typedef struct {
    PQNode *head;
} PriorityQueue;

// Priority Queue Operations
void pq_init(PriorityQueue *pq) {
    pq->head = NULL;
}

int pq_is_empty(PriorityQueue *pq) {
    return pq->head == NULL;
}

void pq_push(PriorityQueue *pq, int vertex, int dist) {
    PQNode *newNode = (PQNode*)malloc(sizeof(PQNode));
    newNode->vertex = vertex;
    newNode->dist = dist;
    newNode->next = pq->head;
    // Note: A true min-heap requires sorting or heap structure. 
    // This simple list insertion is O(N) per push; for O(log V), use a heap structure.
    // For a correct min-heap, you must sort the list or use a heap data structure.
    // Below assumes a sorted insertion for simplicity or a proper heap implementation.
    // In a real implementation, use a heap or sort after insertion.
    // Here we assume the caller maintains order or uses a proper heap library.
    // To keep it simple and correct for the "min" property, we insert in order:
    PQNode *current = pq->head;
    PQNode *prev = NULL;
    while (current && current->dist < dist) {
        prev = current;
        current = current->next;
    }
    newNode->next = current;
    if (prev) prev->next = newNode;
    else pq->head = newNode;
}

int pq_pop(PriorityQueue *pq, int *vertex) {
    if (pq->head == NULL) return 0;
    PQNode *temp = pq->head;
    *vertex = temp->vertex;
    pq->head = temp->next;
    free(temp);
    return 1;
}

// Dijkstra's Algorithm
void dijkstra(Graph *g, int src, int *dist) {
    PriorityQueue pq;
    pq_init(&pq);
    
    // Initialize distances
    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    pq_push(&pq, src, 0);

    while (!pq_is_empty(&pq)) {
        int u;
        pq_pop(&pq, &u);

        // Iterate over neighbors (assuming adjacency matrix for simplicity here)
        // For adjacency list, replace this loop with list traversal
        for (int v = 0; v < g->V; v++) {
            if (g->adj[u][v] != 0) { // Check if edge exists
                int weight = g->adj[u][v];
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq_push(&pq, v, dist[v]);
                }
            }
        }
    }
}   