class Solution {
public:
    int maxProduct(int n) {
        int max = -1, smax = -1;
        while (n > 0) {
            int d = n % 10;
            if (d > max) {
                smax = max;
                max = d;
            } else if (d > smax)
                smax = d;
            n /= 10;
        }
        return max * smax;
    }
};