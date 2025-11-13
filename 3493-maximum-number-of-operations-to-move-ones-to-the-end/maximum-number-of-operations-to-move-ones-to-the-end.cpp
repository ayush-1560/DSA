class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int ops = 0;
        int onesCnt = 0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                ops+=onesCnt;
                while(i<n && s[i]=='0'){
                    i++;
                }
            }
            else {
                onesCnt++;
                i++;
            }
        }
        return ops;
    }
};