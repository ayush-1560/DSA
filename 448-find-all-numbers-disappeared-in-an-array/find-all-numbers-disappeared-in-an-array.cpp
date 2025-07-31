class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int num : nums) st.insert(num);
        vector<int>ans;
        for(int i=1;i<=n;i++) {
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};