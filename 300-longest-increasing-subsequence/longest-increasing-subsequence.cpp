class Solution {
public:
    int solve(int idx,vector<int>&nums,int prev, vector<vector<int>>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev];
        int take=INT_MIN;
        if(prev==-1 || nums[idx]>nums[prev]) take = 1+solve(idx+1,nums,idx,dp);
        int skip = solve(idx+1,nums,prev,dp);
        if(prev!=-1) dp[idx][prev] = max(take,skip);
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(0,nums,prev,dp);
    }
};