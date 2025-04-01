class Solution {
public:
    int minFlips(int a, int b, int c) {
        int temp = (a|b)^c;
        int ans = __builtin_popcount(temp);
        temp&=(a&b);
        ans+=__builtin_popcount(temp);
        return ans;
    }
};