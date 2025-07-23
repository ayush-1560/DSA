class Solution {
public:
    string getStr(string s,string match){
        string str="";
        for(char ch : s){
            if(!str.empty() && str.back()==match[0] && ch==match[1]){
                str.pop_back();
            }
            else str+=ch;
        }
        return str;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;
        string maxStr=x>=y ? "ab":"ba";
        string minStr=x<y?"ab":"ba";
        string pass1 = getStr(s,maxStr);
        score+=(n-pass1.length())/2*max(x,y);
        string pass2 = getStr(pass1,minStr);
        score+=(pass1.length()-pass2.length())/2*min(x,y);
        return score;
    }
};