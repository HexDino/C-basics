#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key[100];
    struct Node *left, *right;
} Node;

void InsertNode(Node **root, char key[]) {
    if (*root == NULL) {
        *root = (Node *)malloc(sizeof(Node));
        strcpy((*root)->key, key);
        (*root)->left = (*root)->right = NULL;
    } else if (strcmp(key, (*root)->key) < 0) {
        InsertNode(&(*root)->left, key);
    } else if (strcmp(key, (*root)->key) > 0) {
        InsertNode(&(*root)->right, key);
    }
}

void DeleteNode(Node **root, char key[]) {
    if (*root != NULL) {
        if (strcmp(key, (*root)->key) < 0) {
            DeleteNode(&(*root)->left, key);
        } else if (strcmp(key, (*root)->key) > 0) {
            DeleteNode(&(*root)->right, key);
        } else {
            if ((*root)->left == NULL && (*root)->right == NULL) {
                free(*root);
                *root = NULL;
            } else if ((*root)->left == NULL) {
                Node *temp = *root;
                *root = (*root)->right;
                free(temp);
            } else if ((*root)->right == NULL) {
                Node *temp = *root;
                *root = (*root)->left;
                free(temp);
            } else {
                Node *temp = (*root)->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }
                strcpy((*root)->key, temp->key);
                DeleteNode(&(*root)->right, temp->key);
            }
        }
    }
}

void PostOrder(Node *root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%s ", root->key);
    }
}

int main (){
    Node *root = NULL;
    char command[100], key[100];
    while (scanf("%s", command), strcmp(command, "#") != 0) {
        if (strcmp(command, "insert") == 0){
            scanf(" %s", key);
            InsertNode(&root, key);
        }
        else if(strcmp(command, "del") == 0){
            scanf(" %s", key);
            DeleteNode(&root, key);
        }
    }
    if (root == NULL) printf("Null\n");
    else PostOrder(root);
    return 0;
}