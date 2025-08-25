class Solution {
public:
    int dp[301][5001];
    int solve(int idx,int amount, vector<int>& coins){
        if(amount==0) return 1;
        if(idx>=coins.size()){
            return 0;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int skip = solve(idx+1,amount,coins);
        int take = 0;
        if(coins[idx]<=amount) take = solve(idx,amount-coins[idx],coins);
        return dp[idx][amount] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins);
    }
};