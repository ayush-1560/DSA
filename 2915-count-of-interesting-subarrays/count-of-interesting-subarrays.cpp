class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0;
        unordered_map<int, long long> modCount;
        modCount[0] = 1;
        int prefix = 0;

        for (int num : nums) {
            if (num % modulo == k) prefix++;
            int rem = prefix % modulo;

            // We want (rem - k + modulo) % modulo to have occurred before
            int target = (rem - k + modulo) % modulo;

            if (modCount.count(target)) {
                count += modCount[target];
            }

            modCount[rem]++;
        }

        return count;
    }
};
