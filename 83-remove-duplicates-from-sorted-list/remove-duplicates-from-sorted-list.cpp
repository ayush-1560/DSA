
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(head->val);
        ListNode* temp=head,*curr=dummy;
        while(temp){
            if(temp->val!=curr->val){
                curr->next=new ListNode(temp->val);
                curr=curr->next;
            }
            temp=temp->next;
        }
        return dummy;
    }
};