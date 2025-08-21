class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        for(int num : nums){
            currsum+=num;
            maxsum = max(maxsum,currsum);
            if(currsum<0) currsum=0;
        }
        return maxsum;
    }
};