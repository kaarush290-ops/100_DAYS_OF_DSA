/*Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

Examples:

Input: cost[][] = [[0, 111], 
                [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.
Input: cost[][] = [[0, 1000, 5000],
                [5000, 0, 1000],
                [1000, 5000, 0]]
Output: 3000
Explanation: We can visit 0->1->2->0 and cost = 1000 + 1000 + 1000 = 3000
Constraints:
1 ≤ cost.size() ≤ 15
0 ≤ cost[i][j] ≤ 104

*/

#include <stdio.h>
#include <limits.h>

#define MAX 15
#define INF 100000000

int n;
int cost[MAX][MAX];
int dp[1<<MAX][MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int mask, int pos) {
    // All cities visited
    if(mask == (1<<n) - 1)
        return cost[pos][0];

    // Already computed
    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for(int city = 0; city < n; city++) {
        if((mask & (1<<city)) == 0) {
            int newAns = cost[pos][city] +
                         tsp(mask | (1<<city), city);

            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    // Initialize dp
    for(int i = 0; i < (1<<n); i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;

    int result = tsp(1, 0); // start from city 0

    printf("%d\n", result);

    return 0;
}