#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateCombinations(int n, int M, int arr[], int start, int sum) {
    if (sum > M) {
        return;
    }
    if (sum == M && start == n) {
        printArray(arr, n);
        return;
    }
    if (start >= n) {
        return;
    }
    for (int i = 1; i <= M; i++) {
        arr[start] = i;
        generateCombinations(n, M, arr, start + 1, sum + i);
    }
}

int main() {
    int n, M;
    scanf("%d %d", &n, &M);
    int arr[n];
    generateCombinations(n, M, arr, 0, 0);
    return 0;
}
