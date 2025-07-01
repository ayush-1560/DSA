class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int ans = 1;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                ans++;
            }
        }
        return ans;
    }
};