#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    int n, i, j;
    int arr[10000];
    char command[20];

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while(1) {
        scanf("%s", command);
        if(strcmp(command, "***") == 0) {
            break;
        }

        if(strcmp(command, "find-max") == 0) {
            int max = INT_MIN;
            for(i = 0; i < n; i++) {
                if(arr[i] > max) {
                    max = arr[i];
                }
            }
            printf("%d\n", max);
        } else if(strcmp(command, "find-min") == 0) {
            int min = INT_MAX;
            for(i = 0; i < n; i++) {
                if(arr[i] < min) {
                    min = arr[i];
                }
            }
            printf("%d\n", min);
        } else if(strcmp(command, "sum") == 0) {
            int sum = 0;
            for(i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("%d\n", sum);
        } else if(strcmp(command, "find-max-segment") == 0) {
            scanf("%d %d", &i, &j);
            int max = INT_MIN;
            for(int k = i-1; k < j; k++) {
                if(arr[k] > max) {
                    max = arr[k];
                }
            }
            printf("%d\n", max);
        }
    }

    return 0;
}
