class Solution {
public:
    int N;
    class DSU{
        public: 
        vector<int> parent;
        vector<int> rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int find (int x) {
            if (x == parent[x]) 
                return x;

            return parent[x] = find(parent[x]);
        }

        void Union (int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
    };
     
    int Kruskal(vector<vector<int>>& edges,int skip_edge,int
    force_edge ){
        int wt=0;
        DSU df(N);
        if(force_edge!=-1){
            df.Union(edges[force_edge][0],edges[force_edge][1]);
            wt+=edges[force_edge][2];
        }
        
        for(int i=0;i<edges.size();i++){
            if(i==skip_edge) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(df.find(u)!=df.find(v)) {
                df.Union(u,v);
                wt+=w;
            }
        }
        for(int i=0;i<N;i++){
            if(df.find(i)!=df.find(0)) return INT_MAX;
        }
        return wt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N=n;
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector
        <int>&b){
            return a[2] < b[2];
        });
        int baseW= Kruskal(edges,-1,-1);
        vector<int>critical,pc;
        for(int i=0;i<edges.size();i++){
            if(Kruskal(edges,i,-1)>baseW) critical.push_back(edges[i][3]);
            else if(Kruskal(edges,-1,i)==baseW) 
            pc.push_back(edges[i][3]);
        }
        return {critical,pc};
    }
};