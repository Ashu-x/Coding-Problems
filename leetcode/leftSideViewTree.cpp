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