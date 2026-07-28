class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if(n==1) return s;
        string ans;
        string tmp;
        for(int i=0;i<n/2;i++){
            tmp+=s[i];
            ans+=s[i];
        }
        sort(ans.begin(),ans.end());
        if(n%2) ans+=s[n/2];
        sort(tmp.begin(),tmp.end(),[](char a, char b){
            return a > b;
        });
        return ans+tmp;
    }
};