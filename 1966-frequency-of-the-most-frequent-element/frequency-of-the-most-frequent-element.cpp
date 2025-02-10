class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0,ans=0;
        long currSum=0;
        for(int r=0;r<n;r++){
            long target=nums[r];
            currSum+=nums[r];
            if(((r-l+1)*target-currSum)>k){
                currSum-=nums[l];
                l++;
            }
            ans= max(ans,r-l+1);
        }
        return ans;
    }
};