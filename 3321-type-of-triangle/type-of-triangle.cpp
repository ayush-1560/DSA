class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]==nums[1] && nums[1]==nums[2]) return "equilateral";
        unordered_map<int,int>mp;
        if(nums[0]+nums[1]>nums[2] && nums[0]+nums[2]>nums[1]
        &&nums[1]+nums[2]>nums[0]){
            if(nums[0]!=nums[1] && nums[1]!=nums[2]) return "scalene";
            mp[nums[0]]++;
            mp[nums[1]]++;
            mp[nums[2]]++;
        }
        for(auto it : mp) if(it.second==2) return "isosceles";

        return "none";
    }
};