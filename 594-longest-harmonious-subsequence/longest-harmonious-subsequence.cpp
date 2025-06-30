class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxLen=0;
        unordered_map<int,int>mp;
        for(int ele : nums) mp[ele]++;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i]+1)){
                maxLen=max(maxLen,mp[nums[i]]+mp[nums[i]+1]);
            }
        }
        return maxLen;
    }
};