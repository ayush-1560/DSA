class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{0,-1,},{0,1},{1,0},{-1,0}};
    void bfs(int i ,int j,vector<vector<int>>& land,int& ex, int &ey){
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ex= max(ex,x);
            ey= max(ey,y);
            for(auto dir : directions){
                int ni = x + dir[0];
                int nj= y + dir[1];
                if(ni>=0 && ni<m && nj>=0 && nj<n && land[ni][nj]==1){
                    land[ni][nj]=0;
                    q.push({ni,nj});
                }
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    int ex=i;
                    int ey=j;
                    bfs(i,j,land,ex,ey);
                    ans.push_back({i,j,ex,ey});
                }
            }
        }
        return ans;
    }
};