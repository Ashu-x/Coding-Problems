vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if(root == NULL) return ans;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<n; i++){
            TreeNode* lvl = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            lvl.push_back(node->val);
        }
        ans.push_back(lvl);
    }
    return ans;
}