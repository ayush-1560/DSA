class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[51][51][102];

    int solve(int idx, int n, int m, int k, int searchCost, int maxSofar) {
        if (idx == n) {
            return (searchCost == k);
        }
        if (dp[idx][searchCost][maxSofar+1] != -1) return dp[idx][searchCost][maxSofar+1];
        
        long long ans = 0;
        for (int i = 1; i <= m; i++) {
            if (i > maxSofar) {
                ans += solve(idx + 1, n, m, k, searchCost + 1, i);
            } else {
                ans += solve(idx + 1, n, m, k, searchCost, maxSofar);
            }
            ans %= MOD;
        }
        return dp[idx][searchCost][maxSofar+1] = ans;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, m, k, 0, 0);
    }
};
