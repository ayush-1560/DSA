class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int currSum=0, count =0;
        for(int num : nums){
            currSum+=num;
            if(currSum==k) count++;
            int req = currSum - k;
            if(mp.count(req)) count+=mp[req];
            mp[currSum]++;
        }
        return count;
    }
};