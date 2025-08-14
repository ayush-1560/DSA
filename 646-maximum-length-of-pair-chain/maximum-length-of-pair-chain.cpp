class Solution {
public:
    int solve(int idx,vector<vector<int>>& pairs,int prev,vector<vector<int>>&dp){
        if(idx>=pairs.size()) return 0;
        if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev];
        int take=0;
        if(prev==-1 || pairs[idx][0]>pairs[prev][1]) take = 1 + solve(idx+1,pairs,idx,dp);
        int skip = solve(idx+1,pairs,prev,dp);
        if(prev!=-1) dp[idx][prev]=max(take,skip);
        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,pairs,-1,dp);
    }
};