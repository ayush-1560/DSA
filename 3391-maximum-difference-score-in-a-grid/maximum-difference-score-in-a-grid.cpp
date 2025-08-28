class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0] = min(grid[i][0],dp[i-1][0]);
        }
        for(int j=1;j<n;j++) dp[0][j] = min(grid[0][j],dp[0][j-1]);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = min({grid[i][j],dp[i-1][j],dp[i][j-1]});
            }
            
        }
        int ans = INT_MIN;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int temp = INT_MAX;
                if((i-1)>=0) temp = min(temp,dp[i-1][j]);
                if((j-1)>=0) temp = min(temp,dp[i][j-1]);
                ans=max(ans,grid[i][j] - temp);
            }
        }
        return ans;
    }
};