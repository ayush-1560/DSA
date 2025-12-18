class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long>profit(n,0);
        long long baseProfit = 0;
        for(int i=0;i<n;i++){
            profit[i] =(1LL)*prices[i]* strategy[i];
            baseProfit+=profit[i];
        } 
        int originalProfit = 0;
        long long maxGain = 0,modifiedProfit=0;
        int i=0,j=0;
        while(j<n){
            originalProfit+=profit[j];
            if(j-i+1>k/2) modifiedProfit+=prices[j];
            if(j-i+1>k){
                originalProfit-=profit[i];
                modifiedProfit-=prices[i+k/2];
                i++;
            }
            if(j-i+1==k){
                maxGain = max(maxGain,modifiedProfit-originalProfit);
            }
            j++;
        }
        return baseProfit + maxGain;
    }
};