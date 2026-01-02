class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = nums[0];
        for(int num : nums) {
            mp[num]++;
            if(mp[num]==nums.size()/2) ans=num;
        }
        return ans;
    }
};