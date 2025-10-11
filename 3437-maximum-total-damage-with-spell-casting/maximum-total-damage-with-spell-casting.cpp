class Solution {
public:
    typedef long long ll;
    ll dp[100000+1];
    unordered_map<ll,ll>mp;
    long long solve(vector<ll>&nums,int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        ll skip = solve(nums,idx+1);
        int j = lower_bound(nums.begin()+idx+1,nums.end(),nums[idx]+3) - nums.begin();
        ll take = mp[nums[idx]]*nums[idx] + solve(nums,j);
        return dp[idx] =  max(take,skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        memset(dp,-1,sizeof(dp));
        for(int ele : power) mp[ele]++;
        vector<ll>nums;
        for(auto it : mp) nums.push_back(it.first);
        sort(nums.begin(),nums.end());
        return solve(nums,0);
    }
};