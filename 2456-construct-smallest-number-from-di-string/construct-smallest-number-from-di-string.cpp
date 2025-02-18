class Solution {
public:
    bool matchPattern(string ans , string pattern){
        for(int i=0;i<pattern.length();i++){
            if(pattern[i]=='I' && ans[i]>ans[i+1]) return false;
            else if(pattern[i]=='D' && ans[i]<ans[i+1])
            return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string ans="";
        for(int i=1;i<=n+1;i++){
            ans.push_back('0'+i);
        }
        while(!matchPattern(ans,pattern)){
            next_permutation(ans.begin(),ans.end());
        }
        return ans;
    }
};