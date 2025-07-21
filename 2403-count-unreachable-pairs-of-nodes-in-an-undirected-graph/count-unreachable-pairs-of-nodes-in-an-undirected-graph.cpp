class Solution {
public:
    unordered_map<int,int>cmpSize;
    int find(int i,vector<int>&parent){
        if(i==parent[i]) return i;
        else return parent[i]=find(parent[i],parent);
    }
    void Union(int x, int y,vector<int>&parent,vector<int>&rank){
        int px = find(x,parent);
        int py = find(y,parent);
        if(px==py) return;
        else{
            if(rank[px]>rank[py]){
                parent[py]=px;
                cmpSize[px]+=cmpSize[py];
            }
            else if(rank[py]>rank[px]){
                parent[px]=py;
                cmpSize[py]+=cmpSize[px];
            }
            else{
                parent[py]=px;
                cmpSize[px]+=cmpSize[py];
                rank[px]++;
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        long long ans=0;
        int remSize=n;
        for(int i=0;i<n;i++) {
            cmpSize[i]=1;
            parent[i]=i;
        }
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            Union(u,v,parent,rank);
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                long long sz=cmpSize[i];
                ans+=sz*(remSize-sz);
                remSize-=sz;
            }
        }
        return ans;
    }
};