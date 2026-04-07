/*Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int parent, int **adj, int *size, bool *visited) {
    visited[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int v = adj[node][i];

        if (!visited[v]) {
            if (dfs(v, node, adj, size, visited))
                return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, int E, int edges[][2]) {
    int **adj = (int **)malloc(V * sizeof(int *));
    int *size = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        adj[i] = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    bool *visited = (bool *)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, size, visited))
                return true;
        }
    }

    return false;
}

int main() {
    int V = 4, E = 4;
    int edges[4][2] = {{0,1},{0,2},{1,2},{2,3}};

    if (isCycle(V, E, edges))
        printf("true");
    else
        printf("false");

    return 0;
}