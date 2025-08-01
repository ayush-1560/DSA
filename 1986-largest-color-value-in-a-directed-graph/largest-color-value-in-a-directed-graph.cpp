class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int>indegree(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        vector<vector<int>>dp(n,vector<int>(26,0));
        queue<int>q;
        vector<int>freq(n);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i][colors[i]-'a']=1;
            }
        }
        int ans = 0;
        int nodes = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            nodes++;
            ans = max(ans,dp[u][colors[u]-'a']);
            for(int v : adj[u]){
                indegree[v]--;
                for(int i=0;i<26;i++){
                    dp[v][i]= max(dp[v][i],dp[u][i]+(colors[v]-'a'==i));
                }
                if(indegree[v]==0) q.push(v);
            }
        }
        return nodes==n ? ans : -1;
    }
};