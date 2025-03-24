class Solution {
public:
    bool isValid(vector<int>& nums, int threshold,int mid){
        int val =0;
        for(auto ele : nums){
            val+=ceil((double)ele/(double)mid);
        }
        return val<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isValid(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};