class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x<=y) return y-x;
        queue<pair<int,int>>q;
        unordered_map<int,bool>vis;
        q.push({x,0});
        vis[x]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node = q.front().first;
                int ops = q.front().second;
                if(node==y) return ops;
                q.pop();
                if(node-1>=0 && vis[node-1]==false){
                    vis[node-1] = true;
                    q.push({node-1,ops+1});
                }
                if(node%5==0 && vis[node/5]==false){
                    vis[node/5]=true;
                    q.push({node/5,ops+1});
                }
                if(node%11==0 && vis[node/11]==false){
                    vis[node/11] = true;
                    q.push({node/11,ops+1});
                }
                if(node+1<=(x+11) && vis[node+1]==false){
                    vis[node+1] = true;
                    q.push({node+1,ops+1});
                }
            }
        }
        return -1;
    }
};