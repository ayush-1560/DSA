class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>vis(n+1,0);
        vector<int>ans(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(A[i]==B[i]) cnt++;
            else{
                if(vis[A[i]]) cnt++;
                if(vis[B[i]]) cnt++;
            }
            vis[A[i]] = 1;
            vis[B[i]] = 1;
            ans[i] = cnt;
        }
        return ans;
    }
};