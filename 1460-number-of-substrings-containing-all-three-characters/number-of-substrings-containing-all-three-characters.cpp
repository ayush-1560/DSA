class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char,int>freq;
        int i=0,j=0;
        long long ans=0;
        while(j<n){
            freq[s[j]]++;
            while(freq['a']>0 && freq['b']>0 && freq['c']>0){
                ans+=n-j;
                freq[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};