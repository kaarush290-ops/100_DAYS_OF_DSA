/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.*/

#include <stdio.h>

#define MAX 10

// Queue structure
typedef struct {
    int x, y;
} Node;

Node queue[100];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Node dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int orangesRotting(int grid[MAX][MAX], int m, int n) {
    int fresh = 0;

    // Step 1: Add all rotten oranges to queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // If no fresh oranges
    if (fresh == 0) return 0;

    int minutes = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // BFS
    while (!isEmpty()) {
        int size = rear - front;
        int changed = 0;

        for (int i = 0; i < size; i++) {
            Node curr = dequeue();

            for (int d = 0; d < 4; d++) {
                int nx = curr.x + dx[d];
                int ny = curr.y + dy[d];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(nx, ny);
                    fresh--;
                    changed = 1;
                }
            }
        }

        if (changed) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}

int main() {
    int m, n;
    int grid[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter grid:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);

    int result = orangesRotting(grid, m, n);

    printf("Output: %d\n", result);

    return 0;
}