class Solution {
public:
    vector<vector<int>>dp;
    int solve(int idx, bool buy, vector<int>& prices) {
        if (idx == prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int take1 = 0, take2 = 0;
        if (buy) {
            take1 = solve(idx + 1, true, prices);
            take2 = -prices[idx] + solve(idx + 1, false, prices);
        } else {
            take1 = solve(idx + 1, false, prices);
            
            take2 = prices[idx] + solve(idx + 1, true, prices);
        }
        return dp[idx][buy]=max(take1, take2);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(0, true, prices);
    }
};
