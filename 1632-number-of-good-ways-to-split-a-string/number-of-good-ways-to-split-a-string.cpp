class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        int cnt=0;
        unordered_set<int>st1,st2;
        vector<int>pre(n,0),suff(n,0);
        for(int i=0;i<s.size();i++){
            st1.insert(s[i]-'a');
            st2.insert(s[n-i-1]-'a');
            pre[i]=st1.size();
            suff[n-i-1]=st2.size();
        }
        for(int i=1;i<pre.size();i++){
            if(pre[i-1]==suff[i]) cnt++;
        }
        return cnt;
    }
};