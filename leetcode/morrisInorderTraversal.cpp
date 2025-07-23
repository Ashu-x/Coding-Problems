vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->val);
            curr = curr->right ;
        }
        else{
            TreeNode* IP = curr->left ;
            while(IP->right != NULL && IP->right != curr){
                IP = IP->right ;
            }
            if(IP->right == NULL){
                IP->right = curr;
                curr = curr->left ;
            }
            else{
                IP->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right ;
            }
        }
    }
    return ans;
}