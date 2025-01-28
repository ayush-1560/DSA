class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(vector<vector<int>>& grid,int i , int j){
      if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0) return 0;
      int sum=grid[i][j];
      grid[i][j]=0;
      for(auto& dir : directions){
        int i_= i+ dir[0];
        int j_= j+ dir[1];
        sum+=dfs(grid,i_,j_);
      }
      return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
       m = grid.size();
       n = grid[0].size();
       int ans = 0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]>0) ans= max(ans,dfs(grid,i,j));
         }
       }
       return ans;
    }
};