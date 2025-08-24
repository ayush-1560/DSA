class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int zc = 0;
        int i=0,j=0;
        while(j<n){
            if(nums[j]==0) zc++;
            while(zc>1){
                if(nums[i]==0) zc--;
                i++;
            }
            maxLen = max(maxLen,j-i);
            j++;
        }
        return maxLen;
    }
};