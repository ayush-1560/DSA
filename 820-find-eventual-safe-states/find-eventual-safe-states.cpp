class Solution {
public:
    bool dfs(int u,vector<vector<int>>& graph,vector<bool>&vis,vector<bool>&inRecursion){
        vis[u]=true;
        inRecursion[u]=true;
        for(int v : graph[u]){
            if(!vis[v] && dfs(v,graph,vis,inRecursion)) return true;
            if(inRecursion[v]) return true;
        }
        inRecursion[u]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>ans;
        vector<bool>vis(n,false);
        vector<bool>inRecursion(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,graph,vis,inRecursion);
        }
        for(int i=0;i<n;i++) {
            if(!inRecursion[i]) ans.push_back(i);
        }
        return ans;
    }
};