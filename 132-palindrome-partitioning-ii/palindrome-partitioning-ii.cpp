class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>>pals(n+1,vector<bool>(n+1,false));
        for(int L =1 ; L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j) pals[i][i]=true;
                else if(s[i]==s[j]){
                    if(L==2) pals[i][j]=true;
                    else pals[i][j] = pals[i+1][j-1];
                }
            }
        }
        vector<int>dp(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(pals[0][i]) dp[i]=0;
            for(int k=0;k<i;k++){
                if(pals[k+1][i] && 1 + dp[k] < dp[i]){
                    dp[i] = 1 + dp[k];
                } 
            }
        }
        return dp[n-1];
    }
};