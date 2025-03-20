class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x) return x;
        else return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        parent[y] = x;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int>cost(n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            cost[i] = -1;
            parent[i] = i;
        }
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int parent_u = find(u);
            int parent_v = find(v);
            if(parent_u!=parent_v){
                cost[parent_u]&=cost[parent_v];
                Union(parent_u,parent_v);
            }
            cost[parent_u]&=w;
        }
        for(auto q : query){
            int s = q[0];
            int t = q[1];
            if(s==t) ans.push_back(0);
            int p1 = find(s);
            int p2 = find(t);
            if(p1!=p2) ans.push_back(-1);
            else ans.push_back(cost[p1]);
        }
        return ans;
    }
};