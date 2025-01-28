class Solution {
public:
    int bfs(vector<vector<int>>& grid,int i ,int j){
        int m = grid.size();
        int n = grid[0].size();
        int sum=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        sum+=grid[i][j];
        grid[i][j]=0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto dir : directions){
                int i_ = i + dir[0];
                int j_ = j+ dir[1];
                if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]>0){
                    sum+=grid[i_][j_];
                    grid[i_][j_]=0;
                    q.push({i_,j_});
                }
            }
       }
       return sum;
    }
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int findMaxFish(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int ans = 0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]>0) ans= max(ans,bfs(grid,i,j));
         }
       }
       return ans;
    }
};