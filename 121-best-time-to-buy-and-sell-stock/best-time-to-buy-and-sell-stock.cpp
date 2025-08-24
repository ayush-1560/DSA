class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minSofar=INT_MAX;
        for(int num : prices){
            minSofar = min(minSofar,num);
            maxP = max(maxP,num-minSofar);
        }
        return maxP;
    }
};