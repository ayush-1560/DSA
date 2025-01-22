class Solution {
public:
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto dir : directions){
                int i_=i+dir[0];
                int j_=j+dir[1];
                if(i_>=0 && i_<m && j_>=0 && j_<n && !vis[i_][j_]){
                    ans[i_][j_] = ans[i][j]+1;
                    vis[i_][j_] = 1;
                    q.push({i_,j_});
                }
            }
        }
        return ans;
    }
};