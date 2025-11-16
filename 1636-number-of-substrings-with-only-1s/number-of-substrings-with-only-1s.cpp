class Solution {
public:
    int numSub(string s) {
        int mod = 1e9+7;
        long long ans = 0;
        long long cnt = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                ans+=((cnt*(cnt+1))/2)%mod;
                cnt=0;
            }
            else cnt++;
        }
        ans+=((cnt*(cnt+1))/2)%mod;
        return ans;
    }
};