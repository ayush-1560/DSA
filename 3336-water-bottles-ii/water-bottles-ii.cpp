class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int exchange = 0;
        while(numBottles>=numExchange){
            numBottles-=numExchange;
            ans++;
            numBottles++;
            numExchange++;
        }
        return ans;
    }
};