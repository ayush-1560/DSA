class Solution {
public:
    int dp[1000001][2][3];
    int solve(int idx, bool buy ,int cap,vector<int>& prices){
        if(cap==0) return 0;
        if(idx==prices.size()) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int take1 =0, take2=0;
        if(buy){
             take1 = -prices[idx] + solve(idx+1,0,cap,prices);
             take2 = solve(idx+1,1,cap,prices);
        }
        else{
            take1 = prices[idx] + solve(idx+1,1,cap-1,prices);
            take2 = solve(idx+1,0,cap,prices);
        }
        return dp[idx][buy][cap] = max(take1,take2);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,2,prices);
    }
};