#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* parent;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* nodes[1000] = {NULL};
Node* root = NULL;

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->parent = NULL;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    return node;
}

void makeRoot(int id) {
    if (nodes[id] == NULL) {
        nodes[id] = makeNode(id);
    }
    root = nodes[id];
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

void PreOrder(Node* node) {
    if (node != NULL) {
        printf("%d ", node->id);
        PreOrder(node->firstChild);
        PreOrder(node->nextSibling);
    }
}

void InOrder(Node* node) {
    if (node != NULL) {
        Node* temp = node->firstChild;
        if (temp != NULL) {
            InOrder(temp);
            temp = temp->nextSibling;
        }
        printf("%d ", node->id);
        while (temp != NULL) {
            InOrder(temp);
            temp = temp->nextSibling;
        }
    }
}

void PostOrder(Node* node) {
    if (node != NULL) {
        Node* temp = node->firstChild;
        while (temp != NULL) {
            PostOrder(temp);
            temp = temp->nextSibling;
        }
        printf("%d ", node->id);
    }
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
        } else if (strcmp(command, "InOrder") == 0){
            InOrder(root);
            printf("\n");
        } else if (strcmp(command, "PreOrder") == 0){
            PreOrder(root);
            printf("\n");
        } else if (strcmp(command, "PostOrder") == 0){
            PostOrder(root);
            printf("\n");
        }
    }
    return 0;
}