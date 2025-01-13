class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>freq;
        for(char ch : s) freq[ch]++;
        int ans=0;
        for(auto it : freq) {
            if(it.second%2) ans+=1;
            else ans+=2;
        }
        return ans; 
    }
};