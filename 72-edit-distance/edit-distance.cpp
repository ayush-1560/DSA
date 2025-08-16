class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string& word1, string& word2){
        if(i==word1.length()){
            return word2.length()-j;
        }
        else if(j==word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return solve(i+1,j+1,word1,word2);
        int insert = 1 + solve(i,j+1,word1,word2);
        int del = 1 + solve(i+1,j,word1,word2);
        int replace = 1 + solve(i+1,j+1,word1,word2);
        return dp[i][j] = min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};