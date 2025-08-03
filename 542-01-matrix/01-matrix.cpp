class Solution {
public:
    vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
          int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto dir : directions){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if(ni>=0 && ni<m &&nj>=0 && nj<n && ans[ni][nj]==-1){
                        ans[ni][nj] = ans[i][j] + 1;
                        q.push({ni,nj});
                    }
                }
        }
        return ans; 
    }
};