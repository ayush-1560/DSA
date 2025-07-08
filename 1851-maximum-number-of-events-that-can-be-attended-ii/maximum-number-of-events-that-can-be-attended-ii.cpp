class Solution {
public:
    int n;
    int bs(vector<vector<int>>& events,int idx){
        int i=idx+1;
        int j=n-1;
        while(i<=j){
            int mid = i+ (j-i)/2;
            if(events[mid][0]>events[idx][1]) j=mid-1;
            else i=mid+1;
        }
        return i;
    }
    int solve(vector<vector<int>>& events, int k,int idx,vector<vector<int>>&dp){
        if(idx>=n || k==0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int skip = solve(events,k,idx+1,dp);
        int nextIdx=bs(events,idx);
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