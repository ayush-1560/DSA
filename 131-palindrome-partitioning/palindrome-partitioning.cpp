class Solution {
public:
    void solve(int i,string&s,vector<string>&part,vector<vector<string>>&ans,vector<vector<bool>>&dp){
        if(i>=s.length()){
            ans.push_back(part);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(dp[i][j]) {
                part.push_back(s.substr(i,j-i+1));
                solve(j+1,s,part,ans,dp);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int L =1 ; L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j) dp[i][i]=true;
                else if(s[i]==s[j]){
                    if(L==2) dp[i][j]=true;
                    else dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        vector<vector<string>>ans;
        vector<string>part;
        solve(0,s,part,ans,dp);
        return ans;
    }
};