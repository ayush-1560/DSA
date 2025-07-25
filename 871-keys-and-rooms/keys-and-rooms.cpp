class Solution {
public:
    void dfs(int u, vector<vector<int>>& rooms, vector<bool>& vis) {
        vis[u] = true;
        for (int v : rooms[u]) {
            if (!vis[v]) {
                dfs(v, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false); // no need of adj here
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        return true;
    }
};