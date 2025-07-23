class Solution {
public:
    typedef pair<int,int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        int cost =0;
        vector<bool>vis(n,false);
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int dist1 = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            cost+=dist1;
            for(auto vec : adj[u]){
                int v = vec.first;
                int dist2 = vec.second;
                if(!vis[v]){
                    pq.push({dist2,v});
                }
            }
        }
        return cost;
    }
};