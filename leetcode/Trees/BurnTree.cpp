// Amount of time to Burn OF infect whole Tree From a given Node => Parent pointer concept
TreeNode* bfsToMarkParent(TreeNode* root , unordered_map<TreeNode*, TreeNode*> &mp, int start){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while(!q.empty()){
        TreeNode* node = q.front();
        if(node->val == start) res = node;
        q.pop();
        if(node->left){
            q.push(node->left);
            mp[node->left] = node;
        }
        if(node->right){
            q.push(node->right);
            mp[node->right] = node;
        }
    }
    return res;
}
int findMaxDist(unordered_map<TreeNode*, TreeNode*> mp, TreeNode* target){
    queue<TreeNode*> q;
    unordered_map<TreeNode*, bool> visited;
    q.push(target);
    visited[target] = true;
    int minTime = 0;
    while(!q.empty()){
        int size = q.size();
        int flag = 0;       // it will tell if we did burn any new node
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){     //checking for left Children
                visited[node->left] = true; 
                flag = 1;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]){   //checking for right children
                visited[node->right] = true;
                flag = 1;
                q.push(node->right);
            }
            if(mp[node] && !visited[mp[node]]){
                visited[mp[node]] = true;
                flag = 1;
                q.push(mp[node]);
            }
        }
        if(flag) minTime++;
    }
    return minTime;
}
int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        TreeNode* target = bfsToMarkParent(root , mp, start);
        int maxi = findMaxDist(mp, target);
        return maxi;
}