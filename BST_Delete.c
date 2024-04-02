#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;
int count = 0;
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
void InOrder(Node *root) {
    if (root != NULL) {
        InOrder(root->left);
        printf("%d ", root->key);
        InOrder(root->right);
    }
}
void PreOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void DeleteKey(Node **root, int key) {
    if (*root == NULL){
        count ++;
        printf("Not found\n");
        return;
    }
    if (key < (*root)->key) {
        DeleteKey(&(*root)->left, key);
    } else if (key > (*root)->key) {
        DeleteKey(&(*root)->right, key);
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
            while (temp->left != NULL) temp = temp->left;
            (*root)->key = temp->key;
            DeleteKey(&(*root)->right, temp->key);
        }
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
        else if (strcmp(command, "delete") == 0){
            int key;
            scanf("%d", &key);
            DeleteKey(&root, key);
            if (count ==0 ) {
                InOrder(root);
                printf("\n");
            }
        }
    }
    return 0;
}