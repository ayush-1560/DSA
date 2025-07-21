class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i==parent[i]) return i;
        else return parent[i] = find(parent[i],parent);
    }
    void Union(int x, int y ,vector<int>&parent,vector<int>&rank,int& cnt){
        int px = find(x,parent);
        int py = find(y,parent);
        if(px==py) return;
        else{
            if(rank[px]>rank[py]){
                parent[py] = px;
            }
            else if(rank[py]>rank[px]){
                parent[px] = py;
            }
            else{
                parent[py] = px;
                rank[px]++;
            }
        }
        cnt--;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int>parent(n);
        vector<int>rank(n,0);
        int cnt=n;
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto edge : connections){
            Union(edge[0],edge[1],parent,rank,cnt);
        }
        return cnt-1;
    }
};