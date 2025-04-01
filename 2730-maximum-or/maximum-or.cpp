class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0), suffix(n + 1, 0);
    
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] | nums[i];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }
        
        long long maxOR = 0;
        
        for (int i = 0; i < n; i++) {
            long long shifted = (long long)nums[i] << k;
            long long restOR = prefix[i] | suffix[i + 1];
            maxOR = max(maxOR, restOR | shifted);
        }
        
        return maxOR;
    }
};