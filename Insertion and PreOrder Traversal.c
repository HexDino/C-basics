#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

void InsertNode(Node **root, int key) {
    if (*root == NULL) {
        *root = (Node *)malloc(sizeof(Node));
        (*root)->key = key;
        (*root)->left = (*root)->right = NULL;
    } else if (key < (*root)->key) {
        InsertNode(&(*root)->left, key);
    } else if (key > (*root)->key) {
        InsertNode(&(*root)->right, key);
    }
}

void PreOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main(){
    Node *root = NULL;
    char command[100];
    while (scanf("%s", command), strcmp(command, "#") != 0) {
        if(strcmp(command, "insert") == 0){
            int key;
            scanf("%d", &key);
            InsertNode(&root, key);
        }
    }
    PreOrder(root);
    return 0;
}