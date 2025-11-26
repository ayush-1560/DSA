#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n, K;
    const long long MOD = 1000000007LL; 
    vector<vector<vector<long long>>> dp;
    vector<vector<int>> *G;

    long long dfs(int i, int j, int rem) {
        if (i == m-1 && j == n-1) {
            return (rem % K == 0) ? 1 : 0;
        }
        long long &ans = dp[i][j][rem];
        if (ans != -1) return ans;

        ans = 0;
        if (i + 1 < m) {
            int nrem = (rem + (*G)[i+1][j]) % K;
            ans += dfs(i+1, j, nrem);
            ans %= MOD;
        }
        if (j + 1 < n) {
            int nrem = (rem + (*G)[i][j+1]) % K;
            ans += dfs(i, j+1, nrem);
            ans %= MOD;
        }
        return ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        K = k;
        G = &grid;
        dp.assign(m, vector<vector<long long>>(n, vector<long long>(K, -1)));

        int startRem = grid[0][0] % K;
        long long result = dfs(0, 0, startRem);
        return (int)result;
    }
};
