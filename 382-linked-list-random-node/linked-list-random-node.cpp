class Solution {
public:
    vector<int>nums;
    Solution(ListNode* head) {
        ListNode* temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int n =nums.size();
        int idx = rand()%n;
        return nums[idx];
    }
};
