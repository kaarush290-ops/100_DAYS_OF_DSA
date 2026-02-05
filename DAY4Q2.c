#include <stdio.h>

// Function to remove all occurrences of val in-place
int removeElement(int nums[], int n, int val) {
    int i = 0;

    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];  
            n--;                   
        } else {
            i++;                   
        }
    }

    return n;  // Number of elements not equal to val
}

int main() {
    int n, val;

    // Input size of array
    scanf("%d", &n);

    int nums[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input value to remove
    scanf("%d", &val);

    // Call function
    int k = removeElement(nums, n, val);

    // Output result
    printf("%d\n", k);  // Number of valid elements

    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
