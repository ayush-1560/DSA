class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
            while(freq[s[i]]>=3){
                freq[s[i]]-=2;
            }
        }
        int ans=0;
        for(auto it : freq) ans+=it.second;
        return ans;
    }
};