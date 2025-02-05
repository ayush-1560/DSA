class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n = points.size();
        int lSum=0,rSum=0,maxSum=0;
        for(int i=0;i<k;i++) lSum+=points[i];
        maxSum=max(maxSum,lSum);
        int rIdx=n-1;
        for(int i=k-1;i>=0;i--){
            lSum-=points[i];
            rSum+=points[rIdx];
            rIdx--;
            maxSum=max(maxSum,(lSum+rSum));
        }
        return maxSum;
    }
};