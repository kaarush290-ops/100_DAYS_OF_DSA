/* Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int **adj, int *size, bool *visited, bool *recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int v = adj[node][i];

        if (!visited[v]) {
            if (dfs(v, adj, size, visited, recStack))
                return true;
        } else if (recStack[v]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

int isCycle(int V, int E, int edges[][2]) {
    int **adj = (int **)malloc(V * sizeof(int *));
    int *size = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        adj[i] = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][size[u]++] = v;
    }

    bool *visited = (bool *)calloc(V, sizeof(bool));
    bool *recStack = (bool *)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, size, visited, recStack))
                return 1;
        }
    }

    return 0;
}

int main() {
    int V = 4, E = 4;
    int edges[4][2] = {{0,1},{1,2},{2,0},{2,3}};

    if (isCycle(V, E, edges))
        printf("YES");
    else
        printf("NO");

    return 0;
}