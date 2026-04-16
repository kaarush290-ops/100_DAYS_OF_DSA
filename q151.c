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

int maxLen(int arr[], int n) {
    int sum = 0, maxLen = 0;
    int map[10000];
    for(int i = 0; i < 10000; i++) map[i] = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            maxLen = i + 1;

        int index = sum + 5000;

        if(map[index] != -1) {
            int len = i - map[index];
            if(len > maxLen)
                maxLen = len;
        } else {
            map[index] = i;
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", maxLen(arr, n));
    return 0;
}