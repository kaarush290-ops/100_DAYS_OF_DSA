/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

Examples:

Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]


Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 
Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]

Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: V = 2, E = 1, edges[][] = [[0, 1]]
Output: 2
Constraints:
1 ≤ V ≤ 106
0 ≤ E ≤ 106
0 ≤ edges[i][0], edges[i][1] < V*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 1000000

int V, E;
int* adj[MAXV];
int degree[MAXV];

int index_counter;
int disc[MAXV];
int low[MAXV];
int inStack[MAXV];
int stack[MAXV];
int top = -1;
int sccCount;

void strong_connect(int u) {
    disc[u] = low[u] = index_counter++;
    stack[++top] = u;
    inStack[u] = 1;

    for (int i = 0; i < degree[u]; i++) {
        int v = adj[u][i];
        if (disc[v] == -1) {
            strong_connect(v);
            if (low[v] < low[u]) low[u] = low[v];
        } else if (inStack[v]) {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }

    if (low[u] == disc[u]) {
        sccCount++;
        while (1) {
            int w = stack[top--];
            inStack[w] = 0;
            if (w == u) break;
        }
    }
}

int findSCC(int V_input, int E_input, int edges[][2]) {
    V = V_input;
    E = E_input;

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)calloc(E, sizeof(int));
        degree[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][degree[u]++] = v;
    }

    index_counter = 0;
    sccCount = 0;
    top = -1;
    for (int i = 0; i < V; i++) {
        disc[i] = -1;
        low[i] = -1;
        inStack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            strong_connect(i);
        }
    }

    for (int i = 0; i < V; i++) free(adj[i]);
    return sccCount;
}