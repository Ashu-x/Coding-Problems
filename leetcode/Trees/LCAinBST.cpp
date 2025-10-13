TreeNode* lcafind(TreeNode* root, TreeNode* p, TreeNode* q){
    while(root != NULL){
        if(root->val < p->val && root->val < q->val) root = root->right;

        if(root->val > p->val && root->val > q->val) root = root->left;

        else return root;
    }
}

//Recursion approach
TreeNode* lcafind(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL) return NULL;
    int curr = root->val;
    if(curr < q->val && curr < p->val){
        return lcafind(root->right, p,q);
    }
    if(curr > q->val && curr > p->val){
        return lcafind(root->left, p,q);
    }
    return root;
}