class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,cnt=0;
        while(i<n && j<m){
            if(s[j]>=g[i]) {
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};