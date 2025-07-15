class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int u ,vector<int>&color,int col){
        color[u]=col;
        for(int v : graph[u]){
            if(color[v]==col) return false;
            else if(color[v]==-1){
                if(!dfs(graph,v,color,!col)) return false; 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(graph,i,color,0)) return false;
            }
        }
        return true;
    }
};