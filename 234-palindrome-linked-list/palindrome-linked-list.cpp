class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=NULL;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head, *second = newHead;
        while(second){
            if(second->val != first->val) return false;
            second = second->next;
            first = first->next;
        }
        reverseList(newHead);
        return true;
    }
};