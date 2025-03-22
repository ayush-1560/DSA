class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int node,vector<bool>&vis,int& v , int& e){
        vis[node]=true;
        v++;
        e+=adj[node].size();
        for(auto ngbr : adj[node]){
            if(!vis[ngbr]){
                dfs(adj,ngbr,vis,v,e);
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
                int v=0,e=0;
                dfs(adj,i,vis,v,e);
                if((v*(v-1))==e) ans++;
            }
        }
        return ans;
    }
};