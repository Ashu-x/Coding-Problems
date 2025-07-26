/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* MergeSort(ListNode* list1 , ListNode* list2){
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1;
                curr = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                curr = list2;
                list2= list2->next;
            }
        }
        if(list1) curr->next = list1;
        else curr->next = list2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;
        ListNode *mid = middle(head);
        ListNode *leftHead = head ;
        ListNode *rightHead = mid->next ;
        mid->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return MergeSort(leftHead , rightHead);
    }
};