void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track){
    queue<TreeNode*> q;     //Doing BFS here for marking parent of each node
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left){
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    unordered_map<TreeNode*,TreeNode*> parent_track; // node -> parent
    markParent(root, parent_track);
    unordered_map<TreeNode*, bool> visited;

    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int curr_dist = 0;

    while(!q.empty()){  //2nd BFS to go upto K distance from target node and using hashtable
        if(curr_dist == k) break;
        curr_dist++;
        int size = q.size();
        for(int i=0; i<size; i++){
            TreeNode* current = q.front();
            q.pop();
            if(!visited[current->left] && current->left){   //For left Child
                q.push(current->left);
                visited[current->left] = true;
            }
            if(!visited[current->right] && current->right){ //For right Child
                q.push(current->right);
                visited[current->right] = true;
            }

            if(parent_track[current] && !visited[parent_track[current]]){   //For Parent node
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> ans;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
    return ans;
}