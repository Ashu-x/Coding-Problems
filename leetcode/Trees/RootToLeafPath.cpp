vector<int> rootToleafPath(TreeNode* root,int target){
    if(root==NULL) return {}
    vector<int> ans;
    array(root,ans, target);
    return ans; 
}

bool array(TreeNode* root, vector<int>& ans){
    if(root==NULL) false;

    ans.push_back(root->val);
    if(target == root->val) return true;
    
    array((root->left, ans, target) || array(root->right, ans, target)){
        return true;
    }
    ans.pop_back();
    return false;
}