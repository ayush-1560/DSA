class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>& nums,vector<int>&v){
        ans.push_back(v);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            solve(i+1,nums,v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        solve(0,nums,v);
        return ans;
    }
};