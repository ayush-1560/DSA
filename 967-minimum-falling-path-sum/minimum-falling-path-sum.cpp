class Solution {
public:
    int helper(vector<vector<int>>& matrix,int i , int j,
    vector<vector<int>>&dp){
        if(j<0 || j>=matrix.size()) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-101) return dp[i][j];
        int s=matrix[i][j]+helper(matrix,i-1,j,dp);
        int left=matrix[i][j]+helper(matrix,i-1,j-1,dp);
        int right=matrix[i][j]+helper(matrix,i-1,j+1,dp);
        return dp[i][j]=min(s,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-101));
        for(int j=0;j<n;j++){
            int ans=helper(matrix,n-1,j,dp);
            mini=min(mini,ans);
        }
        return mini;
    }
};