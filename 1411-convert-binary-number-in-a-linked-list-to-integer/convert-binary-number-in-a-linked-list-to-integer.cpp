class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n = v.size()-1;
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=v[i]*pow(2,n);
            n--;
        }
        return ans;
    }
};