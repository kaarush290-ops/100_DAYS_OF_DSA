/*Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int* visited, int** adj, int* degree) {
    visited[u] = 1;
    for (int i = 0; i < degree[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, visited, adj, degree);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)calloc(n + 1, sizeof(int*));
    int* degree = (int*)calloc(n + 1, sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) adj[i] = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }

    dfs(1, visited, adj, degree);

    int allVisited = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            allVisited = 0;
            break;
        }
    }

    if (allVisited) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj);
    free(degree);
    free(visited);
    return 0;
}