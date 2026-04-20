/*Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int idx;
} Pair;

int longestZeroSumSubarray(int arr[], int n) {
    if (n == 0) return 0;

    int *map = (int*)calloc(2 * n + 1, sizeof(int));
    int offset = n;
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        } else {
            int pos = sum + offset;
            if (map[pos] == 0) {
                map[pos] = i + 1;
            } else {
                int len = i - (map[pos] - 1);
                if (len > maxLen) maxLen = len;
            }
        }
    }

    free(map);
    return maxLen;
}

int main() {
    char buffer[1024];
    int arr[1000];
    int n = 0;

    fgets(buffer, sizeof(buffer), stdin);
    int x;
    while (sscanf(buffer, "%d", &x) == 1) {
        arr[n++] = x;
        buffer += 1+sprintf(buffer, "%d", x);
    }

    int ans = longestZeroSumSubarray(arr, n);
    printf("%d\n", ans);
    return 0;
}