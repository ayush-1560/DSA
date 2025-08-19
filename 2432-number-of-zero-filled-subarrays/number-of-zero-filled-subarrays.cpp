class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int i = 0;
        while (i < n) {
            int l = 0;
            if (nums[i] == 0) {
                while (i < n && nums[i] == 0) {
                    i++;
                    l++;
                }
            } else {
                i++;
            }
            count += (1LL * l * (l + 1)) / 2; 
        }
        return count;
    }
};
