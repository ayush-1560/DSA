class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+1,0);
        int maxi=0;
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n-1;i++){
            dp[i] = max(dp[i-1],nums[i-1]+dp[i-2]);
        }
        maxi = max(maxi,dp[n-1]);
        dp = vector<int>(n+1,0);
        dp[1]=0;
        dp[2]=nums[1];
        for(int i=3;i<=n;i++){
            dp[i] = max(dp[i-1],nums[i-1]+dp[i-2]);
        }
        maxi = max(maxi,dp[n]);
        return maxi;
    }
};