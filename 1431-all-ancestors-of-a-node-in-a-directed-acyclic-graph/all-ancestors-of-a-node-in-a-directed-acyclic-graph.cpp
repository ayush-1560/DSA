class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<vector<int>>ans;
        vector<int> indegree(n, 0);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        vector<int> topoOrder;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            topoOrder.push_back(curr);

            for(int &v : adj[curr]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        vector<set<int>>vec(n);
        for(int node : topoOrder){
            for(int v : adj[node]){
                vec[v].insert(node);
                vec[v].insert(vec[node].begin(),vec[node].end());
            }
        }
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int ele : vec[i]) v.push_back(ele);
            ans.push_back(v);
        }
        return ans;
    }
};