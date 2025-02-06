class Solution {
public:
    void bfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&vis){
        queue<int>q;
        q.push(u);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int& v : adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(adj,i,vis);
                count++;
            }
        }
        return count;
    }
};