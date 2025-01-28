class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        // Process each layer
        for (int layer = 0; layer < layers; layer++) {
            vector<int> temp;
            int top = layer, bottom = m - 1 - layer;
            int left = layer, right = n - 1 - layer;

            // Extract elements in the layer into temp (top → right → bottom → left)
            // Top row
            for (int j = left; j <= right; j++) {
                temp.push_back(grid[top][j]);
            }
            // Right column
            for (int i = top + 1; i <= bottom; i++) {
                temp.push_back(grid[i][right]);
            }
            // Bottom row
            for (int j = right - 1; j >= left; j--) {
                temp.push_back(grid[bottom][j]);
            }
            // Left column
            for (int i = bottom - 1; i > top; i--) {
                temp.push_back(grid[i][left]);
            }

            // Optimize k using modulo operation
            int len = temp.size();
            int effective_k = k % len;

            // Rotate the temp array by effective_k positions
            vector<int> rotated(len);
            for (int i = 0; i < len; i++) {
                rotated[(i + len - effective_k) % len] = temp[i];
            }

            // Write rotated elements back to the grid (in the same layer order)
            int idx = 0;
            // Top row
            for (int j = left; j <= right; j++) {
                grid[top][j] = rotated[idx++];
            }
            // Right column
            for (int i = top + 1; i <= bottom; i++) {
                grid[i][right] = rotated[idx++];
            }
            // Bottom row
            for (int j = right - 1; j >= left; j--) {
                grid[bottom][j] = rotated[idx++];
            }
            // Left column
            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = rotated[idx++];
            }
        }

        return grid;
    }
};
