class Solution {
public:
    bool bfs(vector<vector<int>>& adj,int u ,vector<int>&colors,int col){
        queue<int>q;
        q.push(u);
        colors[u]=col;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int v : adj[node]){
                if(colors[v]==colors[node]) return false;
                else if(colors[v]==-1){
                    colors[v]=!colors[node];
                    q.push(v);
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