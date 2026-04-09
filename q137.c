/* Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1)
        return -1;
    int x = queue[front++];
    if (front > rear)
        front = rear = -1;
    return x;
}

int isEmpty() {
    return front == -1;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    printf("\n");
    return 0;
}