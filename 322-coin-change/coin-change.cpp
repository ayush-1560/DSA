class Solution {
public:
    int dp[12][100001];
    int solve(int idx,vector<int>& coins, int amount){
        if(idx==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int skip = solve(idx-1,coins,amount);
        int take = INT_MAX;
        if(coins[idx]<=amount)    take = 1 + solve(idx,coins,amount-coins[idx]);
        return dp[idx][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int val = solve(coins.size()-1,coins,amount);
        return val==1e9 ? -1 : val;
    }
};