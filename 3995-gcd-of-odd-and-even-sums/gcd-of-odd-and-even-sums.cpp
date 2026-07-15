class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        int i = 1,j=2;
        while(n--){
            sumOdd+=i;
            sumEven+=j;
            i+=2;
            j+=2;
        }
        return gcd(sumOdd,sumEven);
    }
};