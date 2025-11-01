class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode* temp = head;
        ListNode* dummy = new ListNode (-100);
        ListNode* tempD = dummy;
        while(temp){
            if(!st.count(temp->val)) {
                ListNode * newNode = new ListNode(temp->val);
                tempD->next = newNode;
                tempD = tempD->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};