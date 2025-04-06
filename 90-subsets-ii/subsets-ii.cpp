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
        int i = idx+1;
        while(i<nums.size() && nums[i]==nums[i-1]) i++;
        solve(i,nums,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        solve(0,nums,v);
        return ans;
    }
};