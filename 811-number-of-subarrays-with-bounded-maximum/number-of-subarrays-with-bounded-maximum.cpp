class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int l=0,r=0,count=0,m=0;
        while(r<n){
            if(nums[r]>right){
                m=0;
                l=r+1;
            }
            else if(nums[r]>=left && nums[r]<=right){
                m=(r-l+1);
                count+=m;
            }
            else if(nums[r]<left) count+=m;
            r++;
        }
        return count;
    }
};