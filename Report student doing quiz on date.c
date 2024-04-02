#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    int count;
} Record;

int compare(const void *a, const void *b) {
    return strcmp(((Record *)a)->date, ((Record *)b)->date);
}

int main() {
    int capacity = 10;
    int size = 0;
    Record *records = malloc(capacity * sizeof(Record));
    char input[50];
    char info[50];
    while (fgets(input, 11, stdin), input[0] != '*') {
        fgets(info, sizeof(info), stdin);
        char date[11];
        strncpy(date, input, 10);
        date[10] = '\0';

        int i;
        for (i = 0; i < size; i++) {
            if (strcmp(records[i].date, date) == 0) {
                records[i].count++;
                break;
            }
        }

        if (i == size) {
            if (size == capacity) {
                capacity *= 2;
                records = realloc(records, capacity * sizeof(Record));
            }
            strcpy(records[size].date, date);
            records[size].count = 1;
            size++;
        }
        
    }

    qsort(records, size, sizeof(Record), compare);

    for (int i = 0; i < size; i++) {
        printf("%s %d\n", records[i].date, records[i].count);
    }

    free(records);

    return 0;
}
