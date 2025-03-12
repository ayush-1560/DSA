class Solution {
public:
    long long coloredCells(int n) {
        return 1 + (long long)2*(n-1)*n;
    }
};