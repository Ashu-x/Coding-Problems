/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Encodes a tree to a single string.
string serialize(TreeNode* root){
    if(root == NULL) return "";
    string s ="";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node == NULL) s.append("#,");
        else s.append(to_string(node->val)+ ',');
        if(node != NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data){
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* currNode = q.front();
        q.pop();
        getline(s, str, ',');
        if(str == "#") currNode->left = NULL ;      // for left subTree
        else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            currNode->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == "#") currNode->right = NULL ;      // for right subTree
        else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            currNode->right = rightNode;
            q.push(rightNode);
        }   
    }
    return root;
}


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));