class Solution {
public:
    int dp[101][101];
    int solve(int i, int j,vector<vector<int>>& grid,int m , int n){
        if(i==m-1 && j==n-1) return 1;
        if(i<0 | i>=m || j<0 || j>=n || grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solve(i,j+1,grid,m,n);
        int bottom = solve(i+1,j,grid,m,n);
        return dp[i][j] = right + bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size();
        int n = grid[0].size();
        if(grid[m-1][n-1]==1) return 0;
        return solve(0,0,grid,m,n);
    }
};