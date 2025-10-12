int kthLargest(TreeNode* root, int k){
    if(root == NULL) return NULL;

    kthLargest(root->left, k);
    cnt++;
    if(cnt == k) return root->data;
    kthLargest(root->right, k);
}