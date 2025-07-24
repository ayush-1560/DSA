class Solution {
public:
    vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        int minutes=-1;
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        while(!q.empty()){
            int sz=q.size();
            minutes++;
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(auto dir : directions){
                    int x_=x + dir[0];
                    int y_=y + dir[1];
                    if(x_>=0 && x_<m && y_>=0 && y_<n && grid[x_][y_]==1){
                        grid[x_][y_]=2;
                        fresh--;
                        q.push({x_,y_});
                    }
                }
            }
        }
        return fresh==0 ? minutes : -1;
    }
};