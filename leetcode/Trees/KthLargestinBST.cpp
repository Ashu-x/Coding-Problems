int kthSmallest(TreeNode* root, int k){
    if(root == NULL) return -1;

    int fromLeft = kthSmallest(root->left, k);
    if(fromLeft != -1) return fromLeft;
    cnt++;
    if(cnt == k) return root->data;
    return fromRight= kthSmallest(root->right, k);
}

// Reverse INORDER for KTH LARGEST

int kthLargest(TreeNode* root, int k){
    if(root == NULL) return -1;

    int fromRight= kthLargest(root->right, k);
    if(fromRight != -1) return fromRight;
    cnt++;
    if(cnt == k) return root->data;
    return fromLeft = kthLargest(root->left, k);
}

// Using morris reverse preorder traversal
int KthLargestUsingMorrisTraversal(Node *root, int k, int n) {

   // initializing pointer
   Node *currentNode = root;
   Node *KthLargestNode = NULL;

   int counter = 0;

   while (currentNode != NULL) {
      // if the right child is NULL, increment the counter and check
      if (currentNode->right == NULL) {
         counter = counter + 1;
         if (counter == k)
            KthLargestNode = currentNode;

         // else, move to the left child
         currentNode = currentNode->left;
      }

      else {
         // initializing the successorNode.
         Node *successorNode = currentNode->right;

         // moving to the left-most node of successorNode
         while (successorNode->left != NULL && successorNode->left != currentNode)
            successorNode = successorNode->left;

         if (successorNode->left == NULL) {
            // making the successorNode point to currentNode
            successorNode->left = currentNode;

            //  move to the left child of currentNode
            currentNode = currentNode->right;
         }
         else {
            successorNode->left = NULL;

            // increasing the counter and checking
            counter = counter + 1;
            if (counter == k)
               KthLargestNode = currentNode;

            // move to the left child of currentNode
            currentNode = currentNode->left;
         }
      }
   }
   // returning the required element
   return KthLargestNode->data;
}   