class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele : nums) mp[ele]++;
        int ele =nums[0];
        int freq = 1;
        for(auto it : mp){
            if(it.second > freq){
                freq = it.second;
                ele = it.first;
            }
        }
        return ele;
    }
};