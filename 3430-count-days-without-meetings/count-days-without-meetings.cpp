class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());
        int startTime = 0;
        int endTime = 0;
        int ans=0;
        for(auto meeting : meetings){
            if(meeting[0] > endTime){
                ans+=meeting[0]-endTime-1;
            }
            endTime = max(endTime,meeting[1]);
        }
        if(days>endTime){
            ans+=days-endTime;
        }
        return ans;
    }
};