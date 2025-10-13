bool isBST(TreeNode* root, long long minVal, long long maxVal){
    if(root == NULL) return true;

    if(root->val <= minVal || root->val >= maxVal) return false;

    return (isBST(root->left, minVal, root->val)
        && isBST(root->right, root->val, maxVal));
}

bool isValidBST(TreeNode* root){
    return isBST(root, LONG_MIN, LONG_MAX);
}