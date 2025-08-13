class Solution {
public:
    bool isPowerOfThree(int n) {
        for (int x = 0; (long long)x * x <= n; x++) {
            if (pow(3, x) == n) return true;
        }
        return false;
    }
};
