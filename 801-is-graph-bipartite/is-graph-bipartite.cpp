class Solution {
public:
    bool bfs(vector<vector<int>>& adj,int u ,vector<int>&colors,int col){
        queue<pair<int,int>>q;
        q.push({u,col});
        colors[u]=col;
        while(!q.empty()){
            int node = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int v : adj[node]){
                if(colors[v]==col) return false;
                else if(colors[v]==-1){
                    colors[v]=!col;
                    q.push({v,!col});
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(graph,i,color,0)) return false;
            }
        }
        return true;
    }
};