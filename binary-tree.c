#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    
    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void freeTree(struct Node** root) {
    if (*root == NULL) return;
    
    freeTree(&(*root)->left);
    freeTree(&(*root)->right);
    free(*root);
    *root = NULL;

}

const int main(void) {
    struct Node* root = NULL;
    
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);
    inOrder(root);
    printf("\n");
    freeTree(&root);
    
    return 0;
}
