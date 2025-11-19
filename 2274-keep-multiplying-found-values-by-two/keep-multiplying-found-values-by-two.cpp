class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans = original;
        while(st.count(ans)){
            ans*=2;
        }
        return ans;
    }
};