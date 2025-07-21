class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,long long& cmpSize){
        vis[u]=true;
        cmpSize++;
        for(int& v : adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis,cmpSize);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long long ans=0;
        vector<bool>vis(n,false);
        int remNodes=n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long cmpSize=0;
                dfs(i,adj,vis,cmpSize);
                ans+=cmpSize*(remNodes-cmpSize);
                remNodes-=cmpSize;
            }
        }
        return ans;
    }
};