class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int onesCount = 0;
        int minutes = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    onesCount++;
                }
            }
        }
        
        while (!q.empty() && onesCount > 0) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (auto dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    
                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == 1) {
                        grid[i_][j_] = 2;
                        q.push({i_, j_});
                        onesCount--;
                    }
                }
            }
            minutes++;
        }
        
        return (onesCount > 0) ? -1 : minutes;
    }
};
