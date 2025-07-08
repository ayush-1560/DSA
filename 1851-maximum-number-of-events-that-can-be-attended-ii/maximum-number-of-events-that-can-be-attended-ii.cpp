class Solution {
public:
    int n;
    int solve(vector<vector<int>>& events, int k,int idx,vector<vector<int>>&dp){
        if(idx>=n || k==0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int skip = solve(events,k,idx+1,dp);
        int nextIdx=n;
        for(int j=idx+1;j<n;j++){
            if(events[j][0]>events[idx][1]){
                nextIdx=j;
                break;
            }
        }
        int take = events[idx][2]+solve(events,k-1,nextIdx,dp);
        return  dp[idx][k]=max(take,skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return solve(events,k,0,dp);
    }
};