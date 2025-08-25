class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int idx,vector<int>& nums,int sum){
        if(sum==0) return true;
        if(idx>=nums.size()) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool take = false;
        if(nums[idx]<=sum) take = solve(idx+1,nums,sum-nums[idx]);
        bool skip = solve(idx+1,nums,sum);
        return dp[idx][sum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        dp.resize(nums.size()+1,vector<int>((sum/2)+1,-1));
        return solve(0,nums,sum/2);
    }
};