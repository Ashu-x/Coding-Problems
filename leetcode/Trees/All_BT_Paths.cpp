dfs(TreeNode* root, vector<string> &ans, string path){
    if(!root) return ;
    path += to_string(root->val);
    dfs(root->left, ans, path + "->");
    dfs(root->right, ans, path + "->");
    if(root->left == NULL && root->right == NULL) ans.push_back(path);
}

vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path ="";
        dfs(root, ans,path);
        return ans;
}

// USING BACKTRACKING Since it also optimises string temporary creations and deletions

void dfs(TreeNode* root, vector<string> &ans, vector<string> &path) {
    if (!root) return;
    
    path.push_back(to_string(root->val));

    
    if (!root->left && !root->right) {
        // Join path elements into a string
        string fullPath = path[0];
        for (int i = 1; i < path.size(); ++i) {
            fullPath += "->" + path[i];
        }
        ans.push_back(fullPath);
    }
    else {
        dfs(root->left, ans, path);
        dfs(root->right, ans, path);
    }

    // Backtrack: remove the last node added
    path.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    vector<string> path;
    dfs(root, ans, path);
    return ans;
}