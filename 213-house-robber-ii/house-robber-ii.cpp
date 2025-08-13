class Solution {
public:
    int solve(int idx,int n,vector<int>& nums,vector<int>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx] + solve(idx+2,n,nums,dp);
        int skip = solve(idx+1,n,nums,dp);
        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+1,-1);
        int val1 = solve(0,n-1,nums,dp);
        dp = vector<int>(n+1,-1);
        int val2 = solve(1,n,nums,dp);
        return max(val1,val2);
    }
};