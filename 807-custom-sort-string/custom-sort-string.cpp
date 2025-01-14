class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        auto comp = [&mp](char& ch1,char& ch2){
            return (mp[ch1] <mp[ch2]);
        };
        for(int i=0;i<order.length();i++) mp[order[i]] = i;
        sort(s.begin(),s.end(),comp);
        
        return s;
    }
};