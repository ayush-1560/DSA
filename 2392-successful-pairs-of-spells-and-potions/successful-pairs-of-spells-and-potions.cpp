class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            int idx = m;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if ((long long)spells[i] * potions[mid] >= success) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans[i] = m - idx;
        }
        
        return ans;
    }
};
