class Solution {
public:
    int findComplement(int num) {
        int bits = (int)(log2(num)) + 1;
        unsigned int mask = (1U<<bits) -1;
        return num^mask;
    }
};