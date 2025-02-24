class Solution {
public:
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>bobMap;
    int ans;
    bool dfs1(int curr,int t, vector<bool>& vis){
        vis[curr]=true;
        bobMap[curr]=t;
        if(curr==0) return true;
        for(auto& v : adj[curr]){
            if(!vis[v]){
                if(dfs1(v,t+1,vis)) return true;
            }
        }
        bobMap.erase(curr);
        return false;
    }
    void dfs2(int curr, int t, int income, vector<bool>& vis, vector<int>& amount){
        vis[curr] = true;
        if(bobMap.find(curr)==bobMap.end() || t<bobMap[curr]){
            income+=amount[curr];
        }
        else if(t==bobMap[curr]){
            income+=(amount[curr]/2);

        }
        if(adj[curr].size()==1 && curr!=0){
            ans=max(ans,income);
        }
        for(auto& v : adj[curr]){
            if(!vis[v]){
                dfs2(v,t+1,income,vis,amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        ans=INT_MIN;
        int n = amount.size();
        for(auto & edge :edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>vis(n,false);
        dfs1(bob,0,vis);
        vis.assign(n,false);
        dfs2(0,0,0,vis,amount);
        return ans;
    }
};