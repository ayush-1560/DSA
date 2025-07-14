class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&vis){
        vis[u]=true;
        for(int& v : adj[u]){
            if(!vis[v]) dfs(adj,v,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if( i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                cnt++;
            }
        }
        return cnt;
    }
};