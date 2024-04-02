#include <stdio.h>
#include <string.h>

#define MAX_ELEMENT 5

typedef struct {
    char name[50];
    char tel[20];
    char email[25];
} phoneAddr_t;

int search(phoneAddr_t a[], int size, char key[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i].name, key) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char key[50];
    scanf("%s", key);
    phoneAddr_t a[MAX_ELEMENT] = {{"A", "1", "1@"},
                                  {"B", "2", "2@"},
                                  {"C", "3", "3@"},
                                  {"D", "4", "4@"},
                                  {"E", "5", "5@"}};
    printf("%d\n", search(a, 5, key));
    return 0;
}
