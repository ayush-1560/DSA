class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[startTime.size()-1]);
        int n = freeTime.size();
        vector<int>maxRightFree(n,0);
        vector<int>maxLeftFree(n,0);
        for(int i=n-2;i>=0;i--){
            maxRightFree[i] = max(maxRightFree[i+1],freeTime[i+1]);
        }
        for(int i=1;i<n;i++){
            maxLeftFree[i] = max(maxLeftFree[i-1],freeTime[i-1]);
        }
        int ans =0;
        for(int i=1;i<n;i++){
            int eventDur = endTime[i-1] - startTime[i-1];
            if(eventDur <=max(maxLeftFree[i-1],maxRightFree[i])){
                ans = max(ans,freeTime[i-1] + eventDur+freeTime[i]);
            }
            ans = max(ans,freeTime[i-1] + freeTime[i]);
        }
        return ans;
    }
};