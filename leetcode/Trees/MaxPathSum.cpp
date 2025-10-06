int dfs(TreeNode* root, int &res){
    if(root== NULL) return 0;

    int l = dfs(root->left, res);
    int r = dfs(root->right, res);

    int temp = max(root->val, (max(l,r) + root->val)); //wihout split
    int ans = max(temp, root->val + l + r);     // with split
    res = max(res,ans);
    return temp;
}
int maxPathSum(TreeNode* root) {
    int res = root->val;
    dfs(root, res);
    return res;
}