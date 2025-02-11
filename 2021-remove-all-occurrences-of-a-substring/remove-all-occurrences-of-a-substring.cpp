class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        for(char ch : s){
            ans+=ch;
            if(ans.length()>=part.length()){
                if(ans.substr(ans.length()-part.length())==part){
                    ans.erase(ans.length()-part.length());
                }
            }
        }
        return ans;
    }
};