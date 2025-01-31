class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int cummSum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            cummSum+=nums[i];
            if(mp.find(cummSum-k)!=mp.end()) ans+=mp[cummSum-k];
            mp[cummSum]++;
        }
        for(auto it : mp) cout<<it.first<<" "<<it.second<<endl;
        return ans;
    }
};