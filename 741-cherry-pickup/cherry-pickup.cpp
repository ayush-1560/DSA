class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>& grid,int r1, int c1, int r2){
        int c2 = r1 + c1 - r2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1
        || grid[r2][c2]==-1) return INT_MIN;
        if(r1==n-1 && c1==n-1) return grid[r1][c1];
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        int ans = 0;
        if(r1==r2 && c1==c2) ans+=grid[r1][c1];
        else ans+=grid[r1][c1] + grid[r2][c2];
        int next = max({solve(grid,r1+1,c1,r2+1),
                        solve(grid,r1,c1+1,r2),
                        solve(grid,r1+1,c1,r2),
                        solve(grid,r1,c1+1,r2+1)});
        ans+=next;
        return dp[r1][c1][r2] =ans;                
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n= grid.size();
        dp.assign(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = solve(grid,0,0,0);
        return max(0,ans);
    }
};