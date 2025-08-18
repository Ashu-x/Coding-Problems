void flatten(TreeNode* root) {
    while(root != NULL){
        if(root->left != NULL){
            TreeNode* prev = root->left;
            while(prev->right!= NULL) 
                prev = prev->right;
            
            prev->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
            root = root->right;
    }
}