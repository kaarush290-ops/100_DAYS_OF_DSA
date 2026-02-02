#include <stdio.h>

int main() {
    int n;

    // Input number of days
    scanf("%d", &n);

    int prices[n];

    // Input stock prices
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        // If selling today gives profit
        int profit = prices[i] - minPrice;
        if(profit > maxProfit) {
            maxProfit = profit;
        }

        // Update minimum price seen so far
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        }
    }

    printf("%d\n", maxProfit);

    return 0;
}
