class Solution {
public:
    int getDecimalValue(ListNode* head) {
      int decVal=0;
       while(head){
          decVal=(decVal<<1)|(head->val);
          head=head->next;
       }
       return decVal;
    }
};