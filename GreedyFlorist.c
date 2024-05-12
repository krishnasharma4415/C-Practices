#include <stdio.h>
#include <stdlib.h>

int comparePrices(const void *a, const void *b) {
    return *(int *)b - *(int *)a; // Sort prices in descending order
}

int getMinimumCost(int c[], int n, int k) {
    qsort(c, n, sizeof(int), comparePrices); // Sort flower prices

    int total_cost = 0;
    int current_price = 1;

    for (int i = 0; i < n; i++) {
        total_cost += current_price * c[i];
        if ((i + 1) % k == 0) {
            current_price++;
        }
    }

    return total_cost;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Read n (number of flowers) and k (number of friends)

    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]); // Read flower prices
    }

    int min_cost = getMinimumCost(c, n, k);
    printf("%d\n", min_cost);
    return 0;
}
