#include <stdio.h>

int main() {
    int p, q;

    // Read size of first log
    scanf("%d", &p);
    int log1[p];

    // Read first log
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Read size of second log
    scanf("%d", &q);
    int log2[q];

    // Read second log
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int i = 0, j = 0;

    // Merge both logs
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    // Print remaining elements of log1
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    // Print remaining elements of log2
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    return 0;
}
