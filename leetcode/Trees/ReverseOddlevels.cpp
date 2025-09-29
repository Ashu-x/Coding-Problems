void dfs(TreeNode* leftSide, TreeNode* rightSide, int level){
        if(leftSide == NULL || rightSide == NULL) return ;
        if(level%2 == 1){
           swap(leftSide->val , rightSide->val);
        }
        dfs(leftSide->left, rightSide->right , level+1);
        dfs(leftSide->right , rightSide->left , level+1);
    }
    
TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right , 1);
        return root;
}