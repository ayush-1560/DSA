class Solution {
public:
    # define P pair<int,int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<int>d1(n+1,INT_MAX);
        vector<int>d2(n+1,INT_MAX);
        d1[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int node = pq.top().second;
            int timePassed = pq.top().first;
            pq.pop();
            if(node==n && d2[n]!=INT_MAX) return d2[n];
            int div = timePassed/change;
            if(div%2) timePassed = change*(div+1);
            for(int ngbr : adj[node]){
                if(d1[ngbr] > timePassed + time){
                    d2[ngbr] = d1[ngbr];
                    d1[ngbr] = timePassed + time;
                    pq.push({timePassed + time,ngbr});
                }
                else if(d2[ngbr]>timePassed + time && d1[ngbr]!=timePassed + time){
                    d2[ngbr] = timePassed + time;
                    pq.push({timePassed + time,ngbr});
                }
            }
        }
        return -1;
    }
};