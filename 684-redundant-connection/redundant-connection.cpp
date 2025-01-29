class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>&adj,int src, int dest){
        queue<int>q;
        unordered_set<int>vis;
        q.push(src);
        vis.insert(src);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node==dest) return true;
            for(auto it : adj[node]){
                if(!vis.count(it)){
                    q.push(it);
                    vis.insert(it);
                }
            }
        }
        return false;
    }
    bool dfs(unordered_map<int,vector<int>>&adj,int src, int dest,vector<bool>&vis){
        vis[src] = true;
        if(src == dest) return true;
        for(auto& it : adj[src]){
            if(!vis[it]){
                if(dfs(adj,it,dest,vis)) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end()){
                if(bfs(adj,u,v)) return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};