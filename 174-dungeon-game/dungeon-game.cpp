class Solution {
public:
    int dp[201][201];
    int m, n;

    int solve(int i, int j, vector<vector<int>>& grid) {
        if(i>=m || j>=n) return 1e9;
        if(i==m-1 && j==n-1) {
            return grid[i][j] > 0 ? 1 : abs(grid[i][j]) + 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int right = solve(i, j+1, grid);
        int down  = solve(i+1, j, grid);

        int ans = min(right, down) - grid[i][j];
        return dp[i][j] = ans <= 0 ? 1 : ans;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        m = dungeon.size();
        n = dungeon[0].size();
        return solve(0,0,dungeon);
    }
};
