class Solution {
public:
    vector<pair<int,int>>serves ={{100,0},{75,25},{50,50},{25,75}};
    double solve(int A,int B,vector<vector<double>>&dp){
        if(A<=0 && B<=0) return 0.5;
        if(A<=0) return 1.0;
        if(B<=0) return 0.0;
        if(dp[A][B]!=-1) return dp[A][B];
        double prob = 0.0;
        for(auto p : serves){
            int A_taken = p.first;
            int B_taken = p.second;
            prob+=solve(A-A_taken,B-B_taken,dp);
        }
        return dp[A][B] = 0.25*prob;
    }
    double soupServings(int n) {
        if(n>=5000) return 1;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return solve(n,n,dp);
    }
};