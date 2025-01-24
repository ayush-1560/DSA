class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&vis,
    vector<int>&pathVis,vector<int>&check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,check)==true){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>check(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};