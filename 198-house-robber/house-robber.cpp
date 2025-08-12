class Solution {
public:
    int solve(int idx,vector<int>& nums,int sum,vector<int>&dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx] + solve(idx+2,nums,sum,dp);
        int skip = solve(idx+1,nums,sum,dp);
        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int sum=0;
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,sum,dp);
    }
};