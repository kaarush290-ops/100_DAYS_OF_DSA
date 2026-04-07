/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.*/

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

bool canFinish(int numCourses, int prerequisites[][2], int E) {
    int **adj = (int **)malloc(numCourses * sizeof(int *));
    int *size = (int *)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++)
        adj[i] = (int *)malloc(numCourses * sizeof(int));

    for (int i = 0; i < E; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][size[b]++] = a;
    }

    bool *visited = (bool *)calloc(numCourses, sizeof(bool));
    bool *recStack = (bool *)calloc(numCourses, sizeof(bool));

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, size, visited, recStack))
                return false;
        }
    }

    return true;
}

int main() {
    int numCourses = 2;
    int prerequisites[2][2] = {{1,0},{0,1}};
    int E = 2;

    if (canFinish(numCourses, prerequisites, E))
        printf("true");
    else
        printf("false");

    return 0;
}