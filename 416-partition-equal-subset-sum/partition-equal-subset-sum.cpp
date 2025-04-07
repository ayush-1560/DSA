class Solution {
public:
    bool solve(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(idx>=nums.size()){
            return (target==0);
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool take = false;
        if (target - nums[idx] >= 0)
        take = solve(idx + 1, target - nums[idx], nums, dp);
        bool not_take = solve(idx+1,target,nums,dp);
        return dp[idx][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return solve(0,sum/2,nums,dp);
    }
};