#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSymmetric(struct TreeNode* n1, struct TreeNode* n2){
    if(n1 == NULL && n2 == NULL){
         return true;

    }
    else if(n1 == NULL || n2 == NULL){
        return false;
    }
    return(n1->val == n2->val)
        && isSymmetric(n1->left, n2->right)
        && isSymmetric(n1->right, n2->left);
}



struct TreeNode* createNode(int num){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = num;
    node->left = NULL;
    node->right = NULL;
    return node;
};

int main(){

    //first example is symmetricv

    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(2);
    root1->left->left = createNode(3);
    root1->left->right = createNode(4);
    root1->right->left = createNode(4);
    root1->right->right = createNode(3);

    printf("example 1: %s\n", isSymmetric(root1, root1) ? "true" : "false");


    // second example non symmetric

    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(2);
    root2->left->right = createNode(3);
    root2->right->right = createNode(3);

    printf("example 2: %s\n", isSymmetric(root2, root2) ? "true" : "false");



}
