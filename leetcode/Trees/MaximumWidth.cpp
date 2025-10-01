int widthOfBinaryTree(TreeNode* root){
    queue<pair<TreeNode* , unsigned long long>> q;
    q.push({root,1});
    int ans=0;
    while(!q.empty()){
        int currLevelWidth = q.back().second - q.front().second + 1;
        ans = max(ans, currLevelWidth);

        // Store the leftmost position of current level for normalization
        int leftPosition = q.front().second ; 
        int levelSize = q.size();
        for(int i=0; i<levelSize; ++i){
            auto [currentNode, currentPosition] = q.front();
            q.pop();
            // Normalization: subtract (leftmostPosition * 2) to keep indices smaller
            if(currentNode->left){
                int leftChildPosition = (currentPosition << 1) - (leftPosition<<1);
                q.push({currentNode->left , leftChildPosition});
            }
            if(currentNode->right){
                int rightChildPosition = (currentPosition<<1 | 1) - (leftPosition<<1);  //(2 * currentPosition + 1)
                q.push({currentNode->right, rightChildPosition})
            }
        }
    }
    return ans;
}