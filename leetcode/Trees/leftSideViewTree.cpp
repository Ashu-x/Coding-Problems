/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        if(root) q.push(root);
        while(!q.empty()){
            Node* leftValue = nullptr;
            int n=q.size();
            while(n--){
                Node* temp = q.front();
                q.pop();
                if(temp){
                    leftValue = temp;
                    q.push(temp->right);
                    q.push(temp->left);
                }
            }
            if(leftValue != nullptr) ans.push_back(leftValue->data);
        }
        return ans;    
    }
};

// Using DFS
void leftView(TreeNode* root, int currLevel, int & maxLevel){
    if(root == NULL) return  ;
    if(currLevel > maxLevel){
        cout<<root->val<<endl;
        maxLevel = currLevel;
    }
    leftView(root->left, currLevel + 1, maxLevel);
    leftView(root->right, currLevel + 1, maxLevel);
}

leftView(root, 1, maxlevel=0);
