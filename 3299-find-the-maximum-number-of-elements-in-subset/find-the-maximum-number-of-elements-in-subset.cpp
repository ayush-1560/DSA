class Solution {
typedef long long ll;
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        map<ll,int>mp;
        for(int ele : nums) mp[ele]++;
        for(auto [el,freq] : mp){
            ll x = el;
            int count = 0;
            while(mp.count(x) && mp[x]){
                if(x==1) count+=mp[x];
                else if(mp[x]>=2) count+=2;
                else if(mp[x]==1) {count+=1; break;}
                mp[x] = 0;
                if(x>1e6) break;
                x = x*x;
            }
            ans = max(ans,count - (count%2==0));
        }
        return ans;
    }
};