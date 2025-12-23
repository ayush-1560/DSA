class Solution {
public:
    int dp[1000001][3];
    int bs(vector<vector<int>>& events,int endTime){
        int low = 0,high = events.size()-1;
        int idx = events.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            if(events[mid][0]>endTime){
                idx=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return idx;
    }
    int solve(int idx,vector<vector<int>>& events,int count){
        if(count==2 || idx>=events.size()) return 0;
        if(dp[idx][count]!=-1) return dp[idx][count];
        int nextIdx = bs(events,events[idx][1]);
        int take =  events[idx][2] +  solve(nextIdx,events,count+1);
        int skip = solve(idx+1,events,count);
        return dp[idx][count] =  max(take,skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(dp,-1,sizeof(dp));
        sort(events.begin(),events.end());
        int count = 0;
        return solve(0,events,count);
    }
};