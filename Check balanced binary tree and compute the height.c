#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* nodes[50001];

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    nodes[id] = node;
    return node;
}

void addLeft(int id, int parentId) {
    if (nodes[parentId]->left == NULL) {
        nodes[parentId]->left = makeNode(id);
    }
}

void addRight(int id, int parentId) {
    if (nodes[parentId]->right == NULL) {
        nodes[parentId]->right = makeNode(id);
    }
}

void CheckBalance(Node* root, int* isBalanced, int* height) {
    if (root == NULL) {
        *isBalanced = 1;
        *height = -1;
        return;
    }
    int isLeftBalanced, isRightBalanced;
    int leftHeight, rightHeight;
    CheckBalance(root->left, &isLeftBalanced, &leftHeight);
    CheckBalance(root->right, &isRightBalanced, &rightHeight);
    *isBalanced = isLeftBalanced && isRightBalanced && abs(leftHeight - rightHeight) <= 1;
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    Node* root = NULL;
    char command[50001];
    while(scanf("%s", command), strcmp(command, "*") != 0){
        if (strcmp(command, "MakeRoot") == 0){
            int id;
            scanf("%d", &id);
            root = makeNode(id);
        }
        else if (strcmp(command, "AddLeft") == 0){
            int id, parentId;
            scanf("%d %d", &id, &parentId);
            addLeft(id, parentId);
        }
        else if (strcmp(command, "AddRight") == 0){
            int id, parentId;
            scanf("%d %d", &id, &parentId);
            addRight(id, parentId);
        }
    }
    int isBalanced, height;
    CheckBalance(root, &isBalanced, &height);
    printf("%d ", isBalanced);
    printf("%d", height + 1);
    return 0;
}