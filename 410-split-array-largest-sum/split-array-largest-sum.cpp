class Solution {
public:
    int countPartitions(vector<int>& nums,int mid){
        int sum =0, partitions =1;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i]>mid){
                partitions++;
                sum = nums[i];
            }
            else sum+=nums[i];
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(countPartitions(nums,mid)<=k){
                ans=mid;
                high=mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};