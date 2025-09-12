class Solution {
public:
    bool doesAliceWin(string s) {
        return any_of(s.begin(),s.end(),[](char ch){
            return string("aeiou").find(ch)!=string::npos;
        });
    }
};