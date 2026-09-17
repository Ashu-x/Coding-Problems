/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* rightside = nullptr ;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp != nullptr){
                    rightside = temp ;
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            if(rightside != nullptr){
                ans.push_back(rightside->val);
            }
        }
        return ans;
    }
};

void rightView(TreeNode* root, int currLevel, int & maxLevel){
    if(root == NULL) return  ;
    if(currLevel > maxLevel){
        cout<<root->val<<endl;
        maxLevel = currLevel;
    }
    leftView(root->right, currLevel + 1, maxLevel);
    leftView(root->left, currLevel + 1, maxLevel);
}
rightView(root, 1, maxLevel=0);
