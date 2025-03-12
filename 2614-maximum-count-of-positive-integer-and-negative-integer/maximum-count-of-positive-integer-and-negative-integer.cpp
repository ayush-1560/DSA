class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int firstP = lower_bound(nums.begin(),nums.end(),1) - nums.begin();
        int firstZero = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        return max(n-firstP,firstZero);
    }
};