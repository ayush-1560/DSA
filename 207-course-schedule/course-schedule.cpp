class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj, int u, vector<bool>& vis, vector<bool>& inRec) {
        vis[u] = true;
        inRec[u] = true;
        for (int &v : adj[u]) {
            if (!vis[v]) {
                if (!dfs(adj, v, vis, inRec)) return false;  // FIX: Correct logic
            }
            else if (inRec[v]) return false;
        }
        inRec[u] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for (auto &course : prerequisites) {
            adj[course[1]].push_back(course[0]);
        }
        
        vector<bool> vis(numCourses, false);
        vector<bool> inRec(numCourses, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(adj, i, vis, inRec)) return false;
            }
        }
        
        return true;
    }
};
