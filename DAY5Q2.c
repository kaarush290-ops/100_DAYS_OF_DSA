#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;          // Last valid element in nums1
    int j = n - 1;          // Last element in nums2
    int k = m + n - 1;      // Last index of nums1

    // Merge from the back to avoid overwriting
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If nums2 still has elements left
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;

    // Input sizes
    printf("Enter number of elements in nums1 (m): ");
    scanf("%d", &m);

    printf("Enter number of elements in nums2 (n): ");
    scanf("%d", &n);

    int nums1[m + n];
    int nums2[n];

    // Input first m elements of nums1
    printf("Enter %d sorted elements for nums1:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Fill remaining n positions with 0 (placeholders)
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    // Input nums2
    printf("Enter %d sorted elements for nums2:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Merge arrays
    merge(nums1, m, nums2, n);

    // Output result
    printf("Merged array:\n");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
