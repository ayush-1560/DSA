class Solution {
public:
    int m,n;
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        ans[0][0]=0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(int d=0;d<4;d++){
                int ni = i + directions[d][0];
                int nj = j + directions[d][1];
                if(ni>=0 && ni<m && nj>=0 && nj<n){
                    int gridDir = grid[i][j]-1;
                    int currCost =0;
                    currCost = cost + ((d!=gridDir)? 1 : 0);
                    if(currCost < ans[ni][nj]){
                        ans[ni][nj] = currCost;
                        pq.push({currCost,{ni,nj}});
                    } 
                }
            }
        }
        return ans[m-1][n-1];
    }
};