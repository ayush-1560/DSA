class Solution {
public:
    int solve(int idx,vector<int>& nums,int currOr,int maxOr,vector<vector<int>>&dp){
        if(idx==nums.size()) return currOr==maxOr;
        if(dp[idx][currOr]!=-1) return dp[idx][currOr];
        int take = solve(idx+1,nums,currOr|nums[idx],maxOr,dp);
        int skip = solve(idx+1,nums,currOr,maxOr,dp);
        return dp[idx][currOr] = take + skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for(int num : nums) maxOr|=num;
        vector<vector<int>>dp(n,vector<int>(maxOr+1,-1));
        return solve(0,nums,0,maxOr,dp);
    }
};