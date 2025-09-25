ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0) ;
        dummy->next = head;
        ListNode* curr = head;
        ListNode* leftPrev = dummy;

        // step 1: setting leftPrev to node before left 
        for(int i=0; i<left-1 ; i++){
            leftPrev = leftPrev->next;
        }
        curr= leftPrev->next;
        
        // Step 2: reversing from left to right
        ListNode* prev = nullptr;
        for(int i=0; i<right - left + 1; i++){
            ListNode* tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }
        // Step 3: fixing pointers position  
        leftPrev->next->next = curr;
        leftPrev->next = prev;

        return dummy->next;
    }