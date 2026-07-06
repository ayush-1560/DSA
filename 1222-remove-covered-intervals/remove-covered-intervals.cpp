class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [&](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int count = 0;
        int maxRight = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=maxRight) count++;
            else maxRight = intervals[i][1];
        }
        return n-count;
    }
};