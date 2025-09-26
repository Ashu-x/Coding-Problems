void reorderList(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    // Finding the middle of linked list 
    while(fast->next && fast->next->next){
        slow= slow->next;
        fast = fast->next->next;
    }
    // Reversing the second part 
    ListNode* curr = slow->next;
    slow->next = nullptr;
    ListNode* pre = nullptr;
    while(curr){
        ListNode* t = curr->next;
        curr->mext = pre;
        pre = curr;
        curr=t;
    }
    curr = head;
    // Merging both part
    while(pre){
        ListNode* t = pre->next;
        pre->next = curr->next;
        curr->next = pre;
        curr= pre->next;
        pre = t;
    }
}