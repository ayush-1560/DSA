class Solution {
public:
    bool isPred(string s1, string s2){
       if (s2.length() - s1.length() != 1) return false;
        int i=0,j=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]==s2[j]) i++;
            j++;
        }
        return i==s1.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](string s1, string s2){
            return s1.length() < s2.length();
        });
        vector<int>dp(n,1);
        int maxLen = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPred(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                    maxLen = max(maxLen,dp[i]);
                }
            }
        }
        return maxLen;
    }
};