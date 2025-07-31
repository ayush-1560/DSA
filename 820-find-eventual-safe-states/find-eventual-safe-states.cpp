class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indegree(n);
        unordered_map<int,vector<int>>adj;
        for(int i=0 ;i<n;i++){
            for(int v : graph[i]){
                adj[v].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int v : adj[node]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        for(int i=0;i<n;i++){
           if(indegree[i]==0) ans.push_back(i);
        }
        return ans;
    }
};