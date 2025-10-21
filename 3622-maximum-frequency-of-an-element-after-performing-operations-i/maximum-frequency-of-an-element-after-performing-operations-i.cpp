class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(),nums.end());
        vector<int>cumSum(maxEl + k + 1,0);
        for(int num : nums) cumSum[num]++;
        for(int i=1;i<cumSum.size();i++) cumSum[i]+=cumSum[i-1];
        int maxFreq=INT_MIN;
        for(int i=0;i<=maxEl;i++){
            int l = i - k;
            int r = i + k;
            int total = cumSum[r] - (l>0? cumSum[l-1] : 0);
            int targetCount = cumSum[i] -(i>0? cumSum[i-1] : 0);
            int reqrd = total - targetCount;
            reqrd = min(reqrd,numOperations);
            maxFreq = max(maxFreq,reqrd + targetCount);
        }
        return maxFreq;
    }
};