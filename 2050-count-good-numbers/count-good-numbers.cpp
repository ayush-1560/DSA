class Solution {
public:
    int mod = 1e9 + 7;

    long long pow(long long x, long long y) {
        if (y == 0) return 1;

        long long ans = pow(x, y / 2);
        ans = (ans * ans) % mod;

        if (y % 2) ans = (ans * x) % mod;

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = n / 2;
        long long odd = n - even;

        return (pow(5, odd) * pow(4, even)) % mod;
    }
};
