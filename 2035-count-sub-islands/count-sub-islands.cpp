class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0},{0,1},{1,0},{0,-1}};
    bool dfs(int i, int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&vis){
        vis[i][j]=true;
        bool isSubIsland = (grid1[i][j]==1);
        for(auto dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && grid2[ni][nj]==1){
                if(!dfs(ni,nj,grid1,grid2,vis)){
                    isSubIsland = false;
                }
            }
        }
        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid2.size();
        n = grid2[0].size();
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    cnt+=dfs(i,j,grid1,grid2,vis);
                }
            }
        }
        return cnt;
    }
};