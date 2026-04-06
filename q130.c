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

#define MAX 100005

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}

void addEdge(int u, int v) {
    struct Node* n = createNode(v);
    n->next = adj[u];
    adj[u] = n;

    n = createNode(u);
    n->next = adj[v];
    adj[v] = n;
}

int dfs(int node, int parent) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        int neigh = temp->data;

        if (!visited[neigh]) {
            if (dfs(neigh, node))
                return 1;
        } else if (neigh != parent) {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

int isCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V = 4, E = 4;
    int edges[4][2] = {{0,1},{0,2},{1,2},{2,3}};

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        addEdge(edges[i][0], edges[i][1]);
    }

    if (isCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}