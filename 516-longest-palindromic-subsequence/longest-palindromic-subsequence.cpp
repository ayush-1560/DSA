class Solution {
public:
    int LCS(string& s1, string& s2){
        int n = s1.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return LCS(s,s2);
    }
};