class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=0,high = n-1;
        while(low<high){
            int mid = low + (high-low)/2;
            bool isEven = (high-mid)%2==0;
            if(nums[mid]==nums[mid+1]){  //equal case
                if(isEven){
                    low = mid+2;
                }
                else high = mid-1;
            }
            else {
                if(nums[mid]==nums[mid-1]){
                    if(isEven) high =mid-2;
                    else low = mid+1;
                }
                else return nums[mid];
            }
        }
        return nums[low];
    }
};