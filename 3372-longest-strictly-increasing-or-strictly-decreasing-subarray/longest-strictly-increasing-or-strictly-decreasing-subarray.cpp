class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int increasing=1;
        int decreasing =1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                decreasing++;
                increasing=1;
                ans=max(ans,decreasing);
            }
            else if(nums[i]>nums[i-1]){
                increasing++;
                decreasing=1;
                ans=max(ans,increasing);
            }
            else {
                increasing=1;
                decreasing=1;
            }
        }
        return ans;
    }
};