//This aproach follows reverse PostORder traversal => Right Left Root
TreeNode* prev = nullptr;
void flat(TreeNode* node) {
    if (node == nullptr) return;

    flat(node->right);
    flat(node->left);

    node->right = prev;
    node->left = nullptr;
    prev = node;    //Here we are marking prev to node whose reverse postorder is completed
}

void flatten(TreeNode* root) {
    flat(root);
}

//Below is approach where we are preordering and connecting each right node to its root->right
void flatten(TreeNode* root){
    TreeNode* curr = root;
    while(curr != NULL){

        if(curr->left != NULL){
        TreeNode* prev = curr->left;
        while(prev->right) prev = prev->right;
        
        prev->right = curr->right;
        curr->right = curr->left;
        }
        curr = curr->right;
    }
}