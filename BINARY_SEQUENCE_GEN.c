#include <stdio.h>

void printBinary(int n, int arr[], int curr) {
    if (curr == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }

    arr[curr] = 0;
    printBinary(n, arr, curr + 1);

    arr[curr] = 1;
    printBinary(n, arr, curr + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    printBinary(n, arr, 0);
    return 0;
}
