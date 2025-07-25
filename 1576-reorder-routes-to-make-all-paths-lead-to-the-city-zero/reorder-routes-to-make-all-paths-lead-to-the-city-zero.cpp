class Solution {
public:
    int cnt=0;
    void dfs(int u,unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis){
         vis[u]=true;
         for(auto it : adj[u]){
            int v = it.first;
            int edgeType = it.second;
            if(!vis[v]){
                if(edgeType==1) cnt++;
                dfs(v,adj,vis);
            }
         }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto connection : connections){
            adj[connection[0]].push_back({connection[1],1});
            adj[connection[1]].push_back({connection[0],0});
        }
        vector<bool>vis(n,false);
        dfs(0,adj,vis);
        return cnt;
    }
};