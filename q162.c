/*Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

 

Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
 

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
 

Constraints:
1 ≤ V ≤ 105*/

#include <stdio.h>
#include <stdlib.h>

int* articulationPoints(int V, int** adj) {
    int* disc = (int*)calloc(V, sizeof(int));
    int* low = (int*)calloc(V, sizeof(int));
    int* visited = (int*)calloc(V, sizeof(int));
    int* isAP = (int*)calloc(V, sizeof(int));
    int time = 0;

    void dfs(int u, int p) {
        visited[u] = 1;
        disc[u] = low[u] = time++;
        int children = 0;

        for (int i = 0; i < V; i++) {
            if (adj[u][i]) {
                if (i == p) continue;
                if (!visited[i]) {
                    children++;
                    dfs(i, u);
                    low[u] = low[u] < low[i] ? low[u] : low[i];
                    if (p != -1 && low[i] >= disc[u]) {
                        isAP[u] = 1;
                    }
                } else {
                    low[u] = low[u] < disc[i] ? low[u] : disc[i];
                }
            }
        }

        if (p == -1 && children > 1) {
            isAP[u] = 1;
        }
    }

    for (int i = 0; i < V; i++) {
        disc[i] = low[i] = -1;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    int* res = (int*)malloc((V + 1) * sizeof(int));
    int k = 0;
    for (int i = 0; i < V; i++) {
        if (isAP[i]) {
            res[k++] = i;
        }
    }

    if (k == 0) {
        res[0] = -1;
        k = 1;
    }

    free(disc);
    free(low);
    free(visited);
    free(isAP);

    *returnSize = k;
    *returnColumnSizes = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = 1;
    }

    return res;
}