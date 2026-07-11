class Solution {
void dfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis,int& v, int& e){
    vis[node] = true;
    v++;
    e+=adj[node].size();
    for(auto ngbr : adj[node]){
        if(!vis[ngbr]) dfs(ngbr,adj,vis,v,e);
    }
}
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);
        int ans = 0;

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]) {
                int v = 0,e=0;
                dfs(i,adj,vis,v,e);
                if(e==v*(v-1)) ans++;
            }
        }

        return ans;
    }
};