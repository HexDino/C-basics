#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100001

long long hash_table[MAX_SIZE];

void insert(long long k) {
    hash_table[k] = 1;
}

long long find(long long k) {
    return hash_table[k];
}

int main() {
    memset(hash_table, 0, sizeof(hash_table));
    long long k;
    char command[100001];
    while(scanf("%lld", &k) && strcmp(command, "*") != 0) {
        insert(k);
    }
    while(scanf("%s", command) && strcmp(command, "***") != 0) {
        scanf("%lld", &k);
        if (strcmp(command, "find") == 0) {
            printf("%lld\n", find(k));
        } else if (strcmp(command, "insert") == 0) {
            if (find(k)) {
                printf("0\n");
            } else {
                insert(k);
                printf("1\n");
            }
        }
    }
    return 0;
}