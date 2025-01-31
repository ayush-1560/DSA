class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(vector<vector<int>>& grid,int i , int j , int island_id){
      if(i<0 || j<0 || i>=n || j>=n  || grid[i][j]!=1) return 0;
      grid[i][j]=island_id;
      int count =1;
      for(auto dir : directions){
        int x = i + dir[0];
        int y = j + dir[1];
        count+=dfs(grid,x,y,island_id);
      }
      return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int ans =0;
        unordered_map<int,int>mp;
        int island_id =2;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size =dfs(grid,i,j,island_id);
                    ans = max(ans,size);
                    mp[island_id] = size;
                    island_id++;
                }
            }
        }
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    for(auto dir : directions){
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!=0){
                            st.insert(grid[x][y]);
                        }
                    }
                    int sum =1;
                    for(auto ele : st){
                        sum+=mp[ele];
                    }
                    ans = max(ans,sum);
                }
            }
        }
        return ans==0 ? (n*n) : ans;
    }
};
