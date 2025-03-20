class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int l = 1 , r=n-2,ans=-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>nums[mid+1]&& nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
};