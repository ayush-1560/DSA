class Solution {
public:
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<int,vector<int>> PP;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<PP,vector<PP>,greater<>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int row=0;row<m;row++){
            for(int col : {0,n-1}){
                pq.push({heightMap[row][col],{row,col}});
                vis[row][col] = true;
            }
        }
        for(int col=0;col<n;col++){
            for(int row : {0,m-1}){
                pq.push({heightMap[row][col],{row,col}});
                vis[row][col] = true;
            }
        }
        int ans = 0;
        while(!pq.empty()){
            auto [height,cell] = pq.top();
            pq.pop();
            int i = cell[0];
            int j = cell[1];
            for(auto dir : directions ){
                int i_= i + dir[0];
                int j_= j+ dir[1];
                if(i_>=0 && i_<m && j_>=0 && j_<n && !vis[i_][j_]){
                    ans+=max(height -heightMap[i_][j_],0);
                    pq.push({max(height,heightMap[i_][j_]),{i_,j_}});
                    vis[i_][j_] = true;
                }
            }
        }
        return ans;
    }
};