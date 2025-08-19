class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int L =1 ;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j = i+L-1;
                if(i==j) dp[i][j]=1;
                else if(s[i]==s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
