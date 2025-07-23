class Solution {
public:
     vector<int>parent;
    vector<int>rank;
    int find(int i){
        if(i==parent[i]) return i;
        else return parent[i] = find(parent[i]);
    }
    void Union(int x , int y){
        if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else if(rank[y]>rank[x]){
            parent[x]=y;
        }
        else {
            parent[y]=x;
            rank[x]++;
        }
    }
    int kruskal(vector<vector<int>>&adj){
        int sum = 0;
        for(auto vec : adj){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            int u_par = find(u);
            int v_par = find(v);
            if(u_par==v_par) continue;
            Union(u_par,v_par);
            sum+=wt;
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj.push_back({i,j,dist});
            }
        }
        sort(adj.begin(),adj.end(),[&](auto&v1,auto&v2){
            return v1[2] < v2[2];
        });
        return kruskal(adj);
    }
};