class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* reversedHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return reversedHead;
    }
};
