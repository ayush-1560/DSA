class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head,*fast=head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge2lists(ListNode* l1, ListNode* l2){
        ListNode*dummy=new ListNode(-100),*curr=dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                curr->next=l1;
                curr=l1;
                l1=l1->next;
            }
            else {
                curr->next=l2;
                curr=l2;
                l2=l2->next;
            }
        }
        if(l1) curr->next=l1;
        else curr->next=l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head, *rightHead=middle->next;
        middle->next=NULL;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        return merge2lists(leftHead,rightHead);
    }
};