class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans="";
        ans+=s[0];
        int charFreq=1;
        for(int i=1;i<n;i++){
            if(s[i]!=ans.back()){
                charFreq=1;
                ans+=s[i];
            }
            else {
                charFreq++;
                if(charFreq>=3){
                    continue;
                }
                else ans+=s[i];
            }
        }
        return ans;
    }
};