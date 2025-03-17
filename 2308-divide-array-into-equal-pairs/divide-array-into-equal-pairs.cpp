class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele : nums) mp[ele]++;
        int cnt=0;
        for(auto it : mp){
            cnt+=it.second/2;
        }
        return (cnt==nums.size()/2);
    }
};