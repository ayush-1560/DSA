class Solution {
public:
    bool isPowerOfThree(int n) {
        for (int x = 0; x<=30; x++) {
            if (pow(3, x) == n) return true;
        }
        return false;
    }
};