class Solution {
public:
    int MOD = 1e9+7;
    int dp[51][51][101];
    int  solve(int idx,int n,int m, int k, int searchCost,int& maxSofar){
        if(idx>=n) {
            return (searchCost==k);
        }
        if( maxSofar!=-1 && dp[idx][searchCost][maxSofar]!=-1) return dp[idx][searchCost][maxSofar];
        int ans=0;
        for(int i=1;i<=m;i++){
            if(i > maxSofar){
                ans = (ans +solve(idx+1,n,m,k,searchCost+1,i))%MOD;
            }
            else ans = (ans +solve(idx+1,n,m,k,searchCost,maxSofar))%MOD;
        }
        if(maxSofar!=-1) dp[idx][searchCost][maxSofar]=ans%MOD;
        return ans%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        int maxSofar=-1;
        int searchCost=0;
        memset(dp,-1,sizeof(dp));
        return solve(0,n,m,k,searchCost,maxSofar);
    }
};