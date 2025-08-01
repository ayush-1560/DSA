class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indegree(n,0);
        unordered_map<int,vector<int>>adj;
        vector<int>maxTime(n,0);
        queue<int>q;
        for(auto edge : relations){
            adj[edge[0]-1].push_back(edge[1]-1);
            indegree[edge[1]-1]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                maxTime[i]=time[i];
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                maxTime[v]=max(maxTime[v],maxTime[u]+time[v]);
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return *max_element(maxTime.begin(),maxTime.end());
    }
};