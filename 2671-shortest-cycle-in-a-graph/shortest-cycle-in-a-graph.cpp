class Solution {
public:
    int minLen=INT_MAX;
    void bfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<int>&dis){
        queue<pair<int,int>>q;
        q.push({u,-1});
        dis[u]=0;
        vis[u]=true;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int& v : adj[node]){
                if(!vis[v]){
                    vis[v]=true;
                    dis[v] = dis[node] + 1;
                    q.push({v,node});
                }
                else if(v!=parent){
                    minLen = min(minLen,dis[node]+dis[v]+1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            vector<int>dis(n,1e9);
            bfs(i,adj,vis,dis);
        }
        return minLen==INT_MAX ? -1 : minLen;
    }
};