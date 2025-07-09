class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>freeTime;
        freeTime.push_back(startTime[0]-0);
        for(int i=1;i<n;i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[n-1]);
        int i=0,j=0,maxSum=0,sum=0;
        while(j<freeTime.size()){
            sum+=freeTime[j];
            if((j-i+1) > (k+1)){
                sum-=freeTime[i];
                i++;
            }
            maxSum=max(maxSum,sum);
            j++;
        }
        return maxSum;
    }
};