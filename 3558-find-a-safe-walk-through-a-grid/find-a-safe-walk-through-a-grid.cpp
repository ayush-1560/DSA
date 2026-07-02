class Solution {
    int m, n;
    vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};

    bool dfs(int i, int j, vector<vector<int>>& grid,
             int health, vector<vector<int>>& bestHealth) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (grid[i][j] == 1)
            health--;

        if (health < 1)
            return false;

        // We've already been here with >= remaining health.
        if (bestHealth[i][j] >= health)
            return false;

        bestHealth[i][j] = health;

        if (i == m - 1 && j == n - 1)
            return true;

        for (auto &dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (dfs(x, y, grid, health, bestHealth))
                return true;
        }

        return false;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> bestHealth(m, vector<int>(n, -1));

        return dfs(0, 0, grid, health, bestHealth);
    }
};