class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length=0;
        int powerValue=1;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') length++;
            else if(powerValue<=k){
                k-=powerValue;
                length++;
            }
            if(powerValue<=k) powerValue*=2;
        }
        return length;
    }
};