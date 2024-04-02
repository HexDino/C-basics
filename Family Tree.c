#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 10

typedef struct {
    char name[100];
    int children[MAX_PEOPLE];
    int num_children;
} Person;

Person family[MAX_PEOPLE];
int num_people = 0;

int find_person(char *name) {
    for (int i = 0; i < num_people; i++) {
        if (strcmp(family[i].name, name) == 0) {
            return i;
        }
    }
    strcpy(family[num_people].name, name);
    family[num_people].num_children = 0;
    return num_people++;
}

void add_child_to_parent(char *child, char *parent) {
    int child_index = find_person(child);
    int parent_index = find_person(parent);
    family[parent_index].children[family[parent_index].num_children++] = child_index;
}

int count_descendants(int person_index) {
    int count = family[person_index].num_children;
    for (int i = 0; i < family[person_index].num_children; i++) {
        count += count_descendants(family[person_index].children[i]);
    }
    return count;
}

int count_generations(int person_index) {
    int max_generation = 0;
    for (int i = 0; i < family[person_index].num_children; i++) {
        int generation = count_generations(family[person_index].children[i]);
        if (generation > max_generation) {
            max_generation = generation;
        }
    }
    return max_generation + 1;
}

int main() {
    char child[100], parent[100], cmd[100], param[100];

    // Read child-parent pairs
    while (scanf("%s %s", child, parent) == 2, strcmp(child, "***") != 0) {
        add_child_to_parent(child, parent);
    }

    // Process commands
    while (scanf("%s %s", cmd, param) == 2, strcmp(cmd, "***") != 0) {
        int person_index = find_person(param);
        if (strcmp(cmd, "descendants") == 0) {
            printf("%d\n", count_descendants(person_index));
        } else if (strcmp(cmd, "generation") == 0) {
            printf("%d\n", count_generations(person_index) - 1); // Subtract 1 to exclude the person itself
        }
    }

    return 0;
}