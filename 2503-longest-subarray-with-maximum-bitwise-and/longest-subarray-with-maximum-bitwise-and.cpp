class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxE=*max_element(nums.begin(),nums.end());
        int maxLen=1;
        int currLen=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxE){
                currLen++;
                maxLen=max(maxLen,currLen);
            }
            else {
                currLen=0;
            }
        }
        return maxLen;
    }
};