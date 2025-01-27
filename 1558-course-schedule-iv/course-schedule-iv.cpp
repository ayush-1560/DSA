class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int u,int v,vector<bool>&vis){
        vis[u] = true;
        if(u==v) return true;
        bool isReachable = false;
        for(auto it : adj[u]){
            if(!vis[it]){
                isReachable = isReachable ||  dfs(adj,it,v,vis);
            }
        }
        return isReachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(auto ele : prerequisites){
            adj[ele[0]].push_back(ele[1]);
        }
        int n = queries.size();
        vector<bool>ans(n,false);
        for(int i =0;i<n;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            vector<bool>vis(numCourses,false);
            ans[i] = dfs(adj,u,v,vis);
        }
        return ans;
    }
};