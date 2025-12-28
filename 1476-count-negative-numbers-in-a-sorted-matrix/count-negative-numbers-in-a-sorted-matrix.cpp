class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for (auto &v : grid) {
            int low = 0, high = n - 1;
            int firstNeg = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (v[mid] < 0) {
                    firstNeg = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            cnt += (n - firstNeg);
        }
        return cnt;
    }
};
