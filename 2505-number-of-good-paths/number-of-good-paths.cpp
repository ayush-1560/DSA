class DSU{
public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent [i]=i;
            rank[i]=0;
        }
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union ( int x , int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent == y_parent){
            return;
        }
        if(rank[x_parent]> rank[y_parent]){
            parent [y_parent] = x_parent;
        }
        else if(rank[y_parent]>rank[x_parent]){
            parent [x_parent] = y_parent;
        }
        else{
            parent[y_parent] =x_parent;
            rank[x_parent]++;
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        DSU dsu(n);
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        map<int,vector<int>>nodesVal;
        for(int i=0;i<n;i++){
            int val = vals[i];
            nodesVal[val].push_back(i);
        }
        int ans =n;
        vector<bool>isActive(n,false);
        for(auto it : nodesVal){
            vector<int>nodes = it.second;
            for(int u : nodes){
                for(int v : adj[u]){
                    if(isActive[v]){
                        dsu.Union(u,v);
                    }
                }
                isActive[u] = true;
            }
            vector<int>parents;
            for(int u : nodes){
                parents.push_back(dsu.find(u));
            }
            sort(parents.begin(),parents.end());
            for(int j=0;j<parents.size();j++){
                long long count =0;
                int curr_parent = parents[j];
                while(j<parents.size() && curr_parent==parents[j]){
                    j++;
                    count++;
                }
                j--;
                ans+=(count*(count-1))/2;
            }
        }
        return ans;
    }
};