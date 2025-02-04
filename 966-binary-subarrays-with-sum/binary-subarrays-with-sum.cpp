class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            int rem = currSum-goal;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[currSum]++;
        }
        return ans;
    }
};