class Solution {
public:
    int dp[1001][1001];
    bool check(string& s ,int i , int j){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = check(s,i+1,j-1);
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        int maxLen = 0;
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)){
                    if((j-i+1)>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};