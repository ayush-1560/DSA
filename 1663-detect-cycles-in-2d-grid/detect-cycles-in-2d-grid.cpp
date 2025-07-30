class Solution {
public:
    vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    int m;
    int n;
    bool isSafe(int i, int j){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    bool dfs(int i,int j,int pi,int pj,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        for(auto dir : directions){
            int i_= i + dir[0];
            int j_= j+ dir[1];
            if(isSafe(i_,j_) && grid[i_][j_]==grid[i][j]){
                if(!vis[i_][j_]){
                    if(dfs(i_,j_,i,j,grid,vis)) return true;
                }
                else if(i_!=pi && j_!=pj) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid,vis)) return true;
                }
            }
        }
        return false;
    }
};