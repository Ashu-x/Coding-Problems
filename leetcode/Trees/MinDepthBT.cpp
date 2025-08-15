int minDepth(TreeNode* root){
    int depth=1;
    if(!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode* node=q.front();
            q.pop();
            if(node->left == NULL && node->right == NULL) return depth;
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right); 
        }
        depth++;
    }
    return depth;
}