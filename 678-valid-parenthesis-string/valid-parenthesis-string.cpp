class Solution {
public:
    bool solve(string s, int idx, int cnt,vector<vector<int>>&dp){
        if(cnt<0) return false;
        if(dp[idx][cnt]!=-1) return dp[idx][cnt];
        if(idx==s.length()) return cnt==0;
        if(s[idx]=='(') return  dp[idx][cnt]= solve(s,idx+1,cnt+1,dp);
        else if(s[idx]==')') return  dp[idx][cnt]= solve(s,idx+1,cnt-1,dp);
        else{
             return dp[idx][cnt]= solve(s,idx+1,cnt+1,dp) || solve(s,idx+1,cnt-1,dp)
            || solve(s,idx+1,cnt,dp);
        }
    }
    bool checkValidString(string s) {
        int cnt=0;
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(2*n,-1));
        return solve(s,0,cnt,dp);
    }
};