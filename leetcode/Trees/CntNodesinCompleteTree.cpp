int findLeftHeight(TreeNode* node){
    int higt = 0;
    while(node){
        higt++;
        node = node->left;
    }
    return higt;
}

int findRightHeight(TreeNode* node){
    int higt = 0;
    while(node){
        higt++;
        node = node->right;
    }
    return higt;
}
int countNodes(TreeNode* root){
    if(root == NULL) return 0;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if(lh == rh) return (1<<lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}