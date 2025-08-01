class Solution {
public:
    void dfs(int u,int ancestor,unordered_map<int,vector<int>>&adj,vector<vector<int>>&ans){
        for(int v : adj[u]){
            if(ans[v].empty() || ans[v].back()!=ancestor){
                ans[v].push_back(ancestor);
                dfs(v,ancestor,adj,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<vector<int>>ans(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++){
            dfs(i,i,adj,ans);
        }
        return ans;
    }
};