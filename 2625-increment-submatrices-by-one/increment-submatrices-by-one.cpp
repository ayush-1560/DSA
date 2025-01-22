class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        for (auto query : queries){
            int l1=query[0];
            int l2=query[2];
            int r1=query[1];
            int r2=query[3];
            for(int i=l1;i<=l2;i++){
                for(int j=r1;j<=r2;j++){
                    ans[i][j]++;
                }
            }
        }
        return ans;
    }
};