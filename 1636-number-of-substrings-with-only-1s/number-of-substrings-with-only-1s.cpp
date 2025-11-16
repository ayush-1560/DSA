class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        int count = 0;
        int mod = 1e9+7;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count++;
                ans+=count;
            }
            else count = 0;
        }
        return ans%mod;
    }
};