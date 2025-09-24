bool dfs(TreeNode* rootLeft , TreeNode* rootRight){
    if(rootLeft == NULL && rootRight== NULL) return true;
    if(rootLeft == NULL || rootRight == NULL) return false;

    if(rootLeft->val != rootRight->val) return false;
    return (dfs(rootLeft->left , rootRight->right) && (rootLeft->right, rootRight->left));
}

bool SymmetricTree(TreeNode* root){
    if(!root) return false;
    return dfs(root->left, root->right);
}
