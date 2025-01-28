class Solution {
public:
    int findMax(vector<vector<int>>& mat,int m,int n){
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            maxi=max(maxi,mat[i][n]);
        }
        return maxi;
    }
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(mat[i][j]==-1){
                    ans[i][j] = findMax(mat,m,j);
                }
                else ans[i][j]=mat[i][j];
            }
        }
        return ans;
    }
};