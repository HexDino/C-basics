#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* parent;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* nodes[1000];

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->parent = NULL;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    return node;
}

void makeRoot(int id) {
    nodes[id] = makeNode(id);
}

void insert(int u, int v) {
    if (nodes[u] != NULL || nodes[v] == NULL) {
        return;
    }
    Node* node = makeNode(u);
    node->parent = nodes[v];
    if (nodes[v]->firstChild == NULL) {
        nodes[v]->firstChild = node;
    } else {
        Node* sibling = nodes[v]->firstChild;
        while (sibling->nextSibling != NULL) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = node;
    }
    nodes[u] = node;
}

int height(Node* node) {
    if (node == NULL) {
        return -1;
    }
    int maxH = -1;
    Node* child = node->firstChild;
    while (child != NULL) {
        int h = height(child);
        if (h > maxH) {
            maxH = h;
        }
        child = child->nextSibling;
    }
    return maxH + 1;
}

int depth(Node* node) {
    if (node == NULL) {
        return -1;
    }
    int d = 0;
    while (node->parent != NULL) {
        d++;
        node = node->parent;
    }
    return d;
}

int main() {
    char command[100];
    int u, v;
    while (scanf("%s", command), strcmp(command, "*") != 0) {
        if (strcmp(command, "MakeRoot") == 0) {
            scanf("%d", &u);
            makeRoot(u);
        } else if (strcmp(command, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            insert(u, v);
        } else if (strcmp(command, "Height") == 0) {
            scanf("%d", &u);
            printf("%d\n", height(nodes[u]) + 1);
        } else if (strcmp(command, "Depth") == 0) {
            scanf("%d", &u);
            printf("%d\n", depth(nodes[u]) + 1);
        }
    }
    return 0;
}