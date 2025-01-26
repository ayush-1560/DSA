class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        int maxDis = 0;

        while (!q.empty()) {
            auto [currNode, currDis] = q.front();
            q.pop();

            for (auto it : adj[currNode]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, currDis + 1});
                    maxDis = max(maxDis, currDis + 1);
                }
            }
        }
        return maxDis;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            adj[favorite[i]].push_back(i);
        }

        vector<bool> vis(n, false);
        int maxCycleLen = 0;
        int happyEmpCount = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_map<int, int> temp;
                int currNode = i;
                int currNodeCount = 0;

                while (!vis[currNode]) {
                    vis[currNode] = true;
                    temp[currNode] = currNodeCount;
                    int nextNode = favorite[currNode];
                    currNodeCount++;

                    if (temp.count(nextNode)) {
                        int cycleLen = currNodeCount - temp[nextNode];
                        maxCycleLen = max(maxCycleLen, cycleLen);

                        if (cycleLen == 2) {
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;

                            happyEmpCount += 2 + BFS(currNode, adj, visitedNodes)
                                               + BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    }

                    currNode = nextNode;
                }
            }
        }

        return max(maxCycleLen, happyEmpCount);
    }
};
