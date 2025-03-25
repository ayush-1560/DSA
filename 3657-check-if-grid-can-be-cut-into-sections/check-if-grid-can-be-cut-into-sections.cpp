class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        vector<vector<int>> result;

        result.push_back(intervals[0]);
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < result.back()[1]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>intervalsX;
        vector<vector<int>>intervalsY;
        for(auto rectangle : rectangles){
            intervalsX.push_back({rectangle[0],rectangle[2]});
            intervalsY.push_back({rectangle[1],rectangle[3]});
        }
        vector<vector<int>>X= merge(intervalsX);
        if(X.size()>=3) return true;
        vector<vector<int>>Y= merge(intervalsY);
        return Y.size()>=3;
    }
};