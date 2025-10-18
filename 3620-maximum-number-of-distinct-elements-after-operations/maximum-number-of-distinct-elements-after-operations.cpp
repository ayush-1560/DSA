class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums[0]-=k;
        int cnt=1;
        for(int i=1;i<n;i++){
            nums[i] = min(max(nums[i]-k,nums[i-1]+1),nums[i]+k);
            if(nums[i]>nums[i-1]) cnt++;
        }
        return cnt;
    }
};