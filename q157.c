/*Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/

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

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, degree);
            components++;
        }
    }

    printf("%d\n", components);

    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj);
    free(degree);
    free(visited);
    return 0;
}