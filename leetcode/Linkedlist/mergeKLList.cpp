// Follows the priority Q approach having O(N*logK) complextity and space O(K)

struct compare{
        bool operator() (ListNode* a, ListNode* b){
             return (a->val > b->val) ;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>,compare> pq;

        for(ListNode* head:lists){
           if(head!= NULL) pq.push(head);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();

            temp->next = top;
            temp = top;

            if(top->next != NULL) pq.push(top->next);
        }
    return dummy->next;
}

// Idea is to use divide and conquer by recursively splitting the k lists 
// into two halves until we have pairs of lists to merge, then merge these pairs using 
// a two-way merge procedure (similar to merge sort's merge step), and continue this process back up 
// through the recursion tree until all lists are merged into a single sorted list.

ListNode* mergeKLists(vector<ListNode*>& lists){
    if(lists.size() == 0) return NULL;

    return mergeListsRecur(0,lists.size() - 1 , lists);
}

ListNode* mergeTwoLL(ListNode* l1, ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    if(l1->val < l2->val){
        l1->next = mergeTwoLL(l1->next , l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLL(l1, l2->next);
        return l2;
    }
}

ListNode* mergeListsRecur(int left, int right, vector<ListNode*>& lists){
    if(left == right ) return lists[left];

    int mid = left  + (right - left)/2;
    ListNode* l1 = mergeListsRecur(left, mid, lists);
    ListNode* l2 = mergeListsRecur(mid+1, right, lists);
    return mergeTwoLL(l1, l2);
}