class Solution {
public:
    long long solve(int idx, vector<vector<int>>& questions,vector<long long>&dp) {
        int n = questions.size();
        if (idx >= n) return 0;
        
        if (dp[idx] != -1) return dp[idx];
        
        long long take = questions[idx][0] + solve(idx + questions[idx][1] + 1, questions,dp);
        
        long long not_take = solve(idx + 1, questions,dp);
        
        return dp[idx] = max(take, not_take);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,-1);
        return solve(0, questions,dp);
    }
};
