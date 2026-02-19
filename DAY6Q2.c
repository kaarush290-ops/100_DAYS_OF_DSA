#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int j = 0;  // position for next non-zero element

    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            // swap nums[i] and nums[j]
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            j++;
        }
    }

    // Print result
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
