class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minSum=INT_MAX;
        for(int i=0;i<n-1;i++){
            minSum=min(minSum,nums[i+1]-nums[i]);
        }
        return minSum;
    }
};