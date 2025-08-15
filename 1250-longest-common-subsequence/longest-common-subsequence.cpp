class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j,string& text1, string& text2){
        if(i>=text1.length() || j>=text2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]= 1+ solve(i+1,j+1,text1,text2);
        else return dp[i][j]= max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2)); 
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,text1,text2);
    }
};