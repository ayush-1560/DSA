class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        while (!pq.empty()) {
            auto [cost, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;
            
            if (x == n - 1 && y == n - 1) return cost;
            
            for (auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n) {
                    int newCost = max(cost, grid[x_][y_]);
                    if (newCost < dist[x_][y_]) {
                        dist[x_][y_] = newCost;
                        pq.push({newCost, {x_, y_}});
                    }
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};
