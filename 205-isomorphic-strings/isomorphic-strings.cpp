class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_set<char>st;
        for(int i=0;i<s.length();i++){
            if(mp.count(s[i])){
                if(mp[s[i]]!=t[i]) return false;
            }
            else{
                if(st.count(t[i])) return false;
            }
            mp[s[i]]=t[i];
            st.insert(t[i]);
        }
        return true;
    }
};