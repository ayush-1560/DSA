class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int maxSum=INT_MIN;
        while(i<=j){
            int sum=nums[i]+nums[j];
            maxSum=max(sum,maxSum);
            i++;
            j--;
        }
        return maxSum;
    }
};