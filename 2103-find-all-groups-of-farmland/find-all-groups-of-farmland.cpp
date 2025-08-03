class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{0,-1,},{0,1},{1,0},{-1,0}};
    void dfs(int i ,int j,vector<vector<int>>& land,int& ex, int &ey){
        land[i][j]=0;
        ex= max(ex,i);
        ey= max(ey,j);
        for(auto dir : directions){
            int ni = i + dir[0];
            int nj= j + dir[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && land[ni][nj]==1){
                dfs(ni,nj,land,ex,ey);
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
                    dfs(i,j,land,ex,ey);
                    ans.push_back({i,j,ex,ey});
                }
            }
        }
        return ans;
    }
};