class Solution {
public:
    long long dp [1001][501][3];
    long long solve(int i , int k,int CASE,vector<int>& prices){
        if(i>=prices.size()){
            if(CASE==0) return 0;
            return INT_MIN;
        }
        if(dp[i][k][CASE]!=-1) return dp[i][k][CASE];
        long long skip ;
        long long take = INT_MIN;
        skip = solve(i+1,k,CASE,prices);
        if(k>0){
            if(CASE==1){
                take = prices[i] + solve(i+1,k-1,0,prices);
            }
            else if(CASE==2){
                take = -prices[i] + solve(i+1,k-1,0,prices);
            }
            else{
                take = max(
                    -prices[i] + solve(i+1,k,1,prices),
                    prices[i] + solve(i+1,k,2,prices)
                );
            }
        }
        return dp[i][k][CASE] = max(take,skip);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,k,0,prices);
    }
};