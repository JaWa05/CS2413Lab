#include <stdio.h>
#include <stdlib.h>




struct treeNode{
    struct Node *left;
    int data;
    struct Node *right;
}treeNode;

struct TreeNode *makeNode(int val){
    struct treeNode* result = malloc(sizeof(treeNode));
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->data = val;
    }
    return result;
}





void preorderTraversal(struct treeNode *tree){


    if (tree == NULL)
        return;

    // Deal with the node
    printf("%d ", tree->data);

    // Recur on left subtree
    preorderTraversal(tree->left);

    // Recur on right subtree
    preorderTraversal(tree->right);
}


int main(){


    struct treeNode *root = makeNode(1);
    struct treeNode *n2 = makeNode(2);
    struct treeNode *n3 = makeNode(3);

    root->right = n2;
    n2->left = n3;


    preorderTraversal(root);


}

