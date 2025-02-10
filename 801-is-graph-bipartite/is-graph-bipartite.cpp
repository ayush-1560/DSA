class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int u,vector<int>&colors,int currColor){
        colors[u] = currColor;
        for(int& v : graph[u]){
            if(colors[v]==colors[u]) return false;
            else if(colors[v]==-1){
                colors[v]=1-currColor;
                if(dfs(graph,v,colors,colors[v])==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(dfs(graph,i,colors,1)==false) return false;
            }
        }
        return true;
    }
};