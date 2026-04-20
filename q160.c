/*There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000

int n;
int** adj;
int* degree;

int* disc;
int* low;
int* parent;
int time;

int bridges_cnt;
int** bridges;

void add_edge(int u, int v) {
    adj[u][degree[u]++] = v;
}

void dfs(int u) {
    disc[u] = low[u] = time++;
    for (int i = 0; i < degree[u]; i++) {
        int v = adj[u][i];
        if (disc[v] == -1) {
            parent[v] = u;
            dfs(v);
            low[u] = low[u] < low[v] ? low[u] : low[v];
            if (low[v] > disc[u]) {
                int* e = (int*)malloc(2 * sizeof(int));
                e[0] = u;
                e[1] = v;
                bridges[bridges_cnt++] = e;
            }
        } else if (v != parent[u]) {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n_input, int** connections, int connectionsSize,
                          int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    n = n_input;

    adj = (int**)calloc(n, sizeof(int*));
    degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) adj[i] = (int*)calloc(1000, sizeof(int));

    disc = (int*)malloc(n * sizeof(int));
    low = (int*)malloc(n * sizeof(int));
    parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
        parent[i] = -1;
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        add_edge(u, v);
        add_edge(v, u);
    }

    time = 0;
    bridges_cnt = 0;
    bridges = (int**)malloc(100000 * sizeof(int*));

    dfs(0);

    *returnSize = bridges_cnt;
    *returnColumnSizes = (int*)malloc(bridges_cnt * sizeof(int));
    for (int i = 0; i < bridges_cnt; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(degree);
    free(disc);
    free(low);
    free(parent);
    return bridges;
}