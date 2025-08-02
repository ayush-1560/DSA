class Solution {
public:
    vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    int m,n;
    void bfs(int i , int j,vector<vector<char>>& grid, vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first;
            int j=it.second;
            for(auto dir : directions){
                int i_ = i + dir[0];
                int j_ = j+ dir[1];
                if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]=='1' && !vis[i_][j_]){
                    vis[i_][j_]=1;
                    q.push({i_,j_});
                }      
            }
           }
           
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1') {
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};