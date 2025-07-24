class Solution {
public:
    pair<int,int> findNode(unordered_map<int,vector<int>>&adj,int u){
        unordered_map<int,bool>vis;
        queue<int>q;
        q.push(u);
        vis[u]=true;
        int farthestNode = u;
        int maxDist=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int node = q.front();
                q.pop();
                farthestNode = node;
                for(int adjNode : adj[node]){
                    if(!vis[adjNode]){
                        vis[adjNode] = true;
                        q.push(adjNode);
                    }
                }
            }
            if(!q.empty()) maxDist++;
        }
        return {farthestNode,maxDist};
    }
    int diameter(unordered_map<int,vector<int>>&adj){
        auto[farthestNode,dist] = findNode(adj,0);
        auto[otherEndNode,dia] = findNode(adj,farthestNode);
        return dia;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1;
        unordered_map<int,vector<int>>adj2;
        for(auto edge : edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto edge : edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        int D1 = diameter(adj1);
        int D2 = diameter(adj2);
        int D3 = ceil(D1/2.0) + ceil(D2/2.0) + 1;
        return max({D1, D2,D3});
    }
};