class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans =1;
        for(int i=0;i<n;i++){
            int len =1;
            for(int j=i;j<n-1;j++){
                if(nums[j]<nums[j+1]) len++;
                else break;
            }
            ans=max(ans,len);
        }
        for(int i=0;i<n;i++){
            int len =1;
            for(int j=i;j<n-1;j++){
                if(nums[j]>nums[j+1]) len++;
                else break;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};