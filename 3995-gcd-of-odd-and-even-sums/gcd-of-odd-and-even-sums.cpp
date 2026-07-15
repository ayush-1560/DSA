class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1));
    }
};