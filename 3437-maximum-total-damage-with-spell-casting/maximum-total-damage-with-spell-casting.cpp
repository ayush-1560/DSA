class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll>freq;
        for(auto ele : power) freq[ele]++;
        ll n = power.size(), ans=0,prevEl,backEl=0;
        unordered_map<int,ll>dp;
        for(auto f : freq){
            auto el = f.first;
            auto fr = f.second;
            auto backIt = freq.lower_bound(el-2);
            if(backIt != freq.begin()) backEl =(*(--backIt)).first;
            dp[el] = max(dp[prevEl],el*fr + dp[backEl]);
            ans = max(ans,dp[el]);
            prevEl = el;
        }
        return ans;
    }
};