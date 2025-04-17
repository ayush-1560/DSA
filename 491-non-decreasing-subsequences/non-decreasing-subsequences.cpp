class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>& nums,vector<int>&temp){
        if(temp.size()>=2){
            ans.push_back(temp);
        }
        unordered_set<int>st;
        for(int i=idx;i<nums.size();i++){
            if((temp.empty() || temp.back()<=nums[i]) && !st.count(nums[i])){
                temp.push_back(nums[i]);
                solve(i+1,nums,temp);
                temp.pop_back();
                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        solve(0,nums,temp);
        return ans;
    }
};