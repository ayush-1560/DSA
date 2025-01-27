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
    void preProcess(int n, unordered_map<int,vector<int>>&adj,
    vector<vector<bool>>&isPreq){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(u==v) continue;
                vector<bool>vis(n,false);
                if(dfs(adj,u,v,vis)) isPreq[u][v]=true;
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(auto ele : prerequisites){
            adj[ele[0]].push_back(ele[1]);
        }
        vector<vector<bool>>isPreq(numCourses,vector<bool>(numCourses,false));
        preProcess(numCourses,adj,isPreq);
        int n = queries.size();
        vector<bool>ans(n,false);
        for(int i =0;i<n;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] =isPreq[u][v];
        }
        return ans;
    }
};