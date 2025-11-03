class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int time = 0;
        int prev = 0;
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1]){
                prev = 0 ;
            }
            time+=min(neededTime[i],prev);
            prev = max(prev,neededTime[i]);
        }
        return time;
    }
};