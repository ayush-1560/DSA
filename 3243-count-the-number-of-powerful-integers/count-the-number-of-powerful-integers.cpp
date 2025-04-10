class Solution {
public:
    long long solve(string str,string suffStr,int limit){
        if(str.length()<suffStr.length()) return 0;
        long long count = 0;
        string tailStr = str.substr(str.length()-suffStr.length());
        int remLength = str.length()-suffStr.length();
        for(int i=0;i<remLength;i++){
            int digit = str[i]-'0';
            if(digit<=limit){
                count+=digit*pow(limit+1,remLength-i-1);
            }
            else {
                count+=pow(limit+1,remLength-i);
                return count;
            }
        }
        if(tailStr>=suffStr) count+=1;
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);
        return solve(finishStr,s,limit) - solve(startStr,s,limit);
    }
};