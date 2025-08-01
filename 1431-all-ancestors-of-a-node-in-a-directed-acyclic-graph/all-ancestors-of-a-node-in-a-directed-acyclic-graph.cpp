class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
        vis[u]=true;
        for(int v : adj[u]){
            if(!vis[v]) dfs(v,adj,vis);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<vector<int>>ans;
        for(auto edge : edges){
            adj[edge[1]].push_back(edge[0]);
        }
        for(int u=0;u<n;u++){
            vector<int>ancestors;
            vector<bool>vis(n,false);
            dfs(u,adj,vis);
            for(int i=0;i<n;i++){
                if(i==u) continue;
                if(vis[i]) ancestors.push_back(i);
            }
            ans.push_back(ancestors);
        }
        return ans;
    }
};