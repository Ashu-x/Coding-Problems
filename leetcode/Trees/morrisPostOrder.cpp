vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    while(root != NULL){
        if(root->right == NULL){
            ans.push_back(root->val);
            root = root->left ;
        }
        else{
            TreeNode* temp = root->right;
            while(temp->left != NULL && temp->left != root){
                temp = temp->left;
            }
            if(temp->left == NULL){
                temp->left = root;
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                temp->left = NULL;
                root= root->left;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}