#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL) return ;
    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(child >= root->data) root->data = child; //we assinged the root value is if its lesser than sum of its child
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    //As we are coming back to the top we changing root value to sum of child
    if(root->left) tot += root->left->data;
    if(root->right) tot += root->right->data;
    if(root->left || root->right) root->data = tot; 
}  