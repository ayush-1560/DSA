class Solution {
public:
    string removeOccurrences(string s, string part) {
        int idx=-1;
        idx=s.find(part);
        while(idx!=string::npos){
            s.erase(idx,part.length());
            idx=s.find(part);
        }
        return s;
    }
};