#include <stdio.h>

int main() {
    int n;

    // Since array has size n-1, we first input n
    scanf("%d", &n);

    int arr[n-1];
    int sum = 0;

    // Input array elements
    for(int i = 0; i < n-1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Expected sum of numbers from 1 to n
    int total = n * (n + 1) / 2;

    // Missing number
    int missing = total - sum;

    printf("%d\n", missing);

    return 0;
}
