class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>& nums,vector<int>&v){
        if(idx>=nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        solve(idx+1,nums,v);
        v.pop_back();
        solve(idx+1,nums,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        solve(0,nums,v);
        return ans;
    }
};