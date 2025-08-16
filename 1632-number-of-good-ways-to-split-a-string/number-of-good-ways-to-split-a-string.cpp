class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        int cnt=0;
        vector<int>pref(n,0);
        vector<int>suff(n,0);
        unordered_set<int>prefSet;
        unordered_set<int>suffSet;
        for(int i=0;i<n;i++){
            prefSet.insert(s[i]);
            suffSet.insert(s[n-i-1]);
            pref[i]=prefSet.size();
            suff[n-i-1]=suffSet.size();
        }
        for(int i=1;i<n;i++){
            if(pref[i-1]==suff[i]) cnt++;
        }
        return cnt;
    }
};