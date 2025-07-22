class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1},
        {-1, 1}, {-1, -1}, {1, -1}, {1, 1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int pathsum = 0;

        while (!q.empty()) {
            int sz = q.size();
            pathsum++;
            while (sz--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (row == n - 1 && col == n - 1) return pathsum;

                for (auto& dir : directions) {
                    int row_ = row + dir[0];
                    int col_ = col + dir[1];
                    if (row_ >= 0 && row_ < n && col_ >= 0 && col_ < n &&
                        !vis[row_][col_] && grid[row_][col_] == 0) {
                        vis[row_][col_] = true;
                        q.push({row_, col_});
                    }
                }
            }
        }
        return -1;
    }
};
