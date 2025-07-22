class Solution {
public:
    typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto time : times){
            adj[time[0]-1].push_back({time[1]-1,time[2]});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<P,vector<P>,greater<P>>pq;
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto it : adj[u]){
                int v = it.first;
                int wt = it.second;
                if(d+wt < dist[v]){
                    dist[v]=d+wt;
                    pq.push({d+wt,v});
                } 
            }
        }
        int minTime = *max_element(dist.begin(),dist.end());
        return minTime==INT_MAX ? -1 : minTime;
    }
};