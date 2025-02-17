
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode* temp=head;
                while(temp!=slow){
                    slow=slow->next;
                    temp=temp->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};