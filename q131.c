/*Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int parent, int V, int **adj, int *size, bool *visited) {
    visited[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, V, adj, size, visited))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int V = 4;

    int *adj[4];
    int size[4] = {2, 2, 2, 2};

    adj[0] = (int[]){1, 2};
    adj[1] = (int[]){0, 2};
    adj[2] = (int[]){0, 1};
    adj[3] = (int[]){};

    bool visited[4] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V, adj, size, visited)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}