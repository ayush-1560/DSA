class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i'||ch=='o'||ch=='u');
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int l=0,r=0;
        int ans=0;
        int cnt=0;
        while(r<n){
            if((r-l+1) > k){
                cnt-=isVowel(s[l]);
                l++;
            }
            cnt+=isVowel(s[r]);
            if((r-l+1)==k){
                ans=max(ans,cnt);
            }
            r++;
        }
        return ans;
    }
};