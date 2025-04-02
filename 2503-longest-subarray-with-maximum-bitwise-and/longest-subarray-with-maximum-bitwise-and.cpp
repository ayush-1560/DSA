class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxVal = -1;
        int maxLen = 0;
        int currLen=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxVal){
                maxVal=nums[i];
                currLen=1;
                maxLen=1;
            }
            else if(nums[i]==maxVal) {
                currLen++;
            }
            else currLen=0;
            maxLen=max(maxLen,currLen);
        }
        return maxLen;
    }
};