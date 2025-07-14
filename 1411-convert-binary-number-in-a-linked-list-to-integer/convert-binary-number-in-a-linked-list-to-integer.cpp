class Solution {
public:
    int getDecimalValue(ListNode* head) {
       string temp="";
       while(head){
          temp+=to_string(head->val);
          head=head->next;
       }
       int decVal=0;
       reverse(temp.begin(),temp.end());
       for(int i=temp.length()-1;i>=0;i--){
             decVal+=(temp[i]-'0')*pow(2,i);
       }
       return decVal;
    }
};