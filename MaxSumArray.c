// flipping the sign of a negative element in the array increases its contribution to the overall sum. we want to flip the signs of the most negative elements to maximize the sum.

#include <stdio.h>

int maximize_sum(int arr[], int n, int k) {
    // Base cases: no flips or single element
    if (k == 0 || n <= 1) {
        return k == 0 ? 0 : arr[0];
    }

    // Calculate prefix and suffix sums for efficient computations.
    int prefix_sums[n], suffix_sums[n];
    prefix_sums[0] = arr[0];
    suffix_sums[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++) {
        prefix_sums[i] = prefix_sums[i - 1] + arr[i];
        suffix_sums[n - 1 - i] = suffix_sums[n - i] + arr[n - 1 - i];
    }

    // Find maximum gain from flipping adjacent elements.
    int max_gain = 0;
    for (int i = 1; i < n; i++) {
        max_gain = fmax(max_gain, prefix_sums[i - 1] - suffix_sums[i]);
    }

    // Apply flipping operation k times to maximize sum.
    return sum(arr, n) + k * max_gain;
}

// Helper function to calculate the sum of an array.
int sum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int arr[] = {1, 2, -3, 4};
    int k = 2;
    int max_sum = maximize_sum(arr, sizeof(arr) / sizeof(arr[0]), k);
    printf("Max sum after %d flips: %d\n", k, max_sum);
    return 0;
}
