class Solution {
public:
    int dp[501][501];
    int solve(int m,int n,string& word1, string& word2){
        if(m==0 || n==0) return m+n;
        if(dp[m][n]!=-1) return dp[m][n];
        if(word1[m-1]==word2[n-1]) return dp[m][n]=solve(m-1,n-1,word1,word2);
        int insert = 1 + solve(m,n-1,word1,word2);
        int del = 1 + solve(m-1,n,word1,word2);
        int replace = 1 + solve(m-1,n-1,word1,word2);
        return dp[m][n] = min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1.length(),word2.length(),word1,word2);
    }
};