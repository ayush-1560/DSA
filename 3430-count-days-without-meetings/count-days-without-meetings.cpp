class Solution {
public:
    void merge(vector<vector<int>>& intervals,vector<vector<int>>&ans) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        ans.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(start<=ans.back()[1]){
                ans.back()[1]=max(ans.back()[1],end);
            }
            else{
                ans.push_back({start,end});
            }
        }
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>>ans;
        merge(meetings,ans);
        for(auto ele : ans){
            int diff = ele[1]-ele[0]+1;
            days-=diff;
        }
        return days;
    }
};