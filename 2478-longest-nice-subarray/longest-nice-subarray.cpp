class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen =1;
        int i=0,j=0,mask=0;
        while(j<n){
            while((mask&nums[j])!=0){
                mask = (mask^nums[i]);
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            mask=(mask|nums[j]);
            j++;
        }
        return maxLen;
    }
};