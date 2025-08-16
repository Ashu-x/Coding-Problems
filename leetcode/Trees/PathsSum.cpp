// Given the root of a binary tree and an integer targetSum, 
// return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root== NULL) return false;
    
    if(root->left == NULL && right->right == NULL){
        if(targetSum == node->val) return true;
    }
    bool leftSubtree = hasPathSum(root->left , targetSum - node->val);
    bool rightSubtree = hasPathSum(root->right , targetSum - node->val);
    
    return leftSubtree || rightSubtree ;
}