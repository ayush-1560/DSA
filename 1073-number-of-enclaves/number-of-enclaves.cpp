class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i, int j,vector<vector<int>>& grid){
        grid[i][j]=0;
        for(auto dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1) dfs(ni,nj,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]==1){
                        dfs(i,j,grid);
                    }
                } 
            }
        }
        int enclaves = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) enclaves++;
            }
        }
        return enclaves;
    }
};