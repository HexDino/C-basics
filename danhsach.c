#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001

typedef struct Student {
    char name[100];
    char email[100];
    struct Student* leftChild;
    struct Student* rightChild;
} Student;

Student* hash_table[MAX_SIZE];





int main() {
    memset(hash_table, 0, sizeof(hash_table));
    char command[10];
    char name[100];
    char email[100];
    while (scanf("%s", command) != EOF && strcmp(command, "Quit") != 0) {
        if (strcmp(command, "Find") == 0) {
            scanf("%s", name);
            Student* student = find(name);
            if (student != NULL) {
                printf("%s %s\n", student->name, student->email);
            }
        } else if (strcmp(command, "Insert") == 0) {
            scanf("%s %s", name, email);
            insert(name, email);
        } else if (strcmp(command, "Remove") == 0) {
            scanf("%s", name);
            removes(name);
        }
    }
    printf("Bye\n");
    return 0;
}