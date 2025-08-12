class Solution {
public:
    int M=1e9+7;
    int solve(int n,int x,int num,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(pow(num,x)>n) return 0;
        if(dp[n][num]!=-1) return dp[n][num];
        int take = solve(n-pow(num,x),x,num+1,dp);
        int skip = solve(n,x,num+1,dp);
        return dp[n][num]=(take + skip)%M;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int num=pow(1,x);
        return solve(n,x,num,dp);
    }
};