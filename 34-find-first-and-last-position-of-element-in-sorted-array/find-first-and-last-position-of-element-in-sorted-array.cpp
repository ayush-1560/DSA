class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0 , high = n-1,secondIdx=-1,firstIdx=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                firstIdx=mid;
                high = mid-1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low = mid+1;
        }
        low=0,high=n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                secondIdx=mid;
                low = mid+1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low = mid+1;
        }
        return {firstIdx,secondIdx};
    }
};