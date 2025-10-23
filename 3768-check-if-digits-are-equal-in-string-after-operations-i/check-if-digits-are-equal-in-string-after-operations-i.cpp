class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()!=2){
            string temp="";
            int i=0;
            int j=1;
            while(j<s.length()){
                temp.push_back((s[i]-'0' + s[j]-'0')%10 +'0');
                i++;
                j++;
            }
            s=temp;
        }
        return s[0]==s[1];
    }
};