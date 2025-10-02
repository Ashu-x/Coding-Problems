//QUE => Remove every node which has a node with a greater value anywhere to the right side of it.
// Return the head of the modified linked list.

ListNode* reverseLL(ListNode* head){    //Reversing linkedlist
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseLL(head);
        ListNode* temp = head;
        ListNode* prev = head;
        int mx=temp->val;
        temp = temp->next;
        while(temp){
            if(temp->val >= mx){
                prev = temp ;
                mx = temp->val;
            }
            else{
                prev->next = temp->next;
            }
            temp= temp->next;
        }
        prev->next = nullptr;
        return reverseLL(head);
}