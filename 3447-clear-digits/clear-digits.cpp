class Solution {
public:
    string clearDigits(string s) {
        int i=0,j=0;
        while(i<s.length()){
            if(isdigit(s[i])){
                j=max(j-1,0);
            }
            else{
                s[j]=s[i];
                j++;
            }
            i++;
        }
        return s.substr(0,j);
    }
};