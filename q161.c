/*Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1000

int adj[MAXN][MAXN];
int n, m;

int prim() {
    int parent[MAXN];
    int key[MAXN];
    int inMST[MAXN];
    int total = 0;

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[1] = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    return total;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int ans = prim();
    printf("%d\n", ans);
    return 0;
}