class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        for(auto dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==0 && !vis[ni][nj]) dfs(ni,nj,grid,vis);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int islands = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]==0) dfs(i,j,grid,vis);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !vis[i][j]) {
                    dfs(i,j,grid,vis);
                    islands++;
                }
            }
        }
        return islands;
    }
};