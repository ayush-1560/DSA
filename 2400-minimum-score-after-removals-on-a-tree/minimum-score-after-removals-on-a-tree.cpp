class Solution {
public:
    void dfs(int node, int parent,vector<int>&subtreeXor,vector<int>&inTime,vector<int>&outTime,int& timer,
    vector<int>& nums,unordered_map<int,vector<int>>&adj){
        subtreeXor[node]=nums[node];
        inTime[node]=timer;
        timer++;
        for(int ngbr : adj[node]){
            if(ngbr!=parent){
                dfs(ngbr,node,subtreeXor,inTime,outTime,timer,nums,adj);
                subtreeXor[node]^=subtreeXor[ngbr];
            }
        }
        outTime[node]=timer;
        timer++;
    }
    bool isAncestor(int u, int v,vector<int>&inTime,vector<int>&outTime){
        return inTime[v]>=inTime[u] && outTime[v]<=outTime[u];
    }
    int getScore(int xor1, int xor2,int xor3){
        int maxVal = max({xor1,xor2,xor3});
        int minVal = min({xor1,xor2,xor3});
        return maxVal - minVal;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>subtreeXor(n,0);
        vector<int>inTime(n,0);
        vector<int>outTime(n,0);
        int timer = 0;
        dfs(0,-1,subtreeXor,inTime,outTime,timer,nums,adj);
        int ans = INT_MAX;
        for(int u = 1;u<n;u++){
            for(int v=u+1;v<n;v++){
                int xor1;
                int xor2;
                int xor3;
                if(isAncestor(u,v,inTime,outTime)){
                    xor1=subtreeXor[v];
                    xor2=subtreeXor[u]^subtreeXor[v];
                    xor3=subtreeXor[0]^xor1^xor2;
                }
                else if(isAncestor(v,u,inTime,outTime)){
                    xor1=subtreeXor[u];
                    xor2=subtreeXor[u]^subtreeXor[v];
                    xor3=subtreeXor[0]^xor1^xor2;
                }
                else{
                    xor1=subtreeXor[u];
                    xor2=subtreeXor[v];
                    xor3=subtreeXor[0]^xor1^xor2;
                }
                ans=min(ans,getScore(xor1,xor2,xor3));
            }
        }
        return ans;
    }
};