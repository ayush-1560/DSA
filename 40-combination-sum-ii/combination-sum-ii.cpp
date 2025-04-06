class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,int target,vector<int>&nums,vector<int>&v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            v.push_back(nums[i]);
            solve(i+1,target-nums[i],nums,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,v);
        return ans;
    }
};