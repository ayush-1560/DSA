class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int node,vector<bool>&vis,unordered_set<int>&components){
        vis[node]=true;
        components.insert(node);
        for(auto ngbr : adj[node]){
            if(!vis[ngbr]){
                dfs(adj,ngbr,vis,components);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                unordered_set<int>components;
                dfs(adj,i,vis,components);
                int k = components.size();
                int reqEdges = (k*(k-1))/2;
                int actualEdges = 0;
                for(int node : components) actualEdges+=adj[node].size();
                actualEdges/=2;
                if(actualEdges==reqEdges) ans++;
            }
        }
        return ans;
    }
};