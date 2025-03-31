class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int>pairSum(n-1);
        for(int i=0;i<n-1;i++){
            pairSum[i] = weights[i] + weights[i+1];
        }
        sort(pairSum.begin(),pairSum.end());
        long long maxSum=0,minSum=0;
        for(int i=0;i<k-1;i++){
            minSum+=pairSum[i];
            maxSum+=pairSum[n-1-i-1];
        }
        return maxSum-minSum;
    }
};