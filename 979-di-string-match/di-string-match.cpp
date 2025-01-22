class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<bool>vis(n,false);
        vector<int>ans(n);
        int i=0,j=n;
        for(int k=0;k<n;k++){
            if(s[k]=='I') {
                if(!vis[i]){
                    ans[k]=i;
                    vis[i] = true;
                    i++;
                }
            }
            else{
                if(!vis[j]){
                    ans[k]=j;
                    vis[j]=true;
                    j--;
                }
            }
        }
        for(int i=0;i<=n;i++) if(!vis[i]) ans.push_back(i);
        return ans;
    }
};