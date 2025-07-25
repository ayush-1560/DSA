class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
        vis[u]=true;
        for(int& v : adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<n;u++){
            for(int v : rooms[u]){
              if(v!=u){
                adj[u].push_back(v);
              }
            }
        }
        vector<bool>vis(n,false);
        dfs(0,adj,vis);
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        return true;
    }
};