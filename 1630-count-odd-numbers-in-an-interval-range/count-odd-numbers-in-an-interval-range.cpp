class Solution {
public:
    int countOdds(int low, int high) {
        auto f = [](int x) { return (x + 1) / 2; };
        return f(high) - f(low - 1);
    }
};