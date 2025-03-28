class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;
        for(auto ele : nums) totalXor^=ele;
        return __builtin_popcount(totalXor^k);
    }
};