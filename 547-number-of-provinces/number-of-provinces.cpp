class Solution {
public:
    void bfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&vis){
        queue<int>q;
        q.push(u);
        vis[u]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int v : adj[node]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if( i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(adj,i,vis);
                cnt++;
            } 
        }
        return cnt;
    }
};