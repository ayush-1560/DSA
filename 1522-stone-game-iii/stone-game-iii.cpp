class Solution {
int n;
int dp[500001];
int solve(vector<int>& stoneValue,int i){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int result  = stoneValue[i] - solve(stoneValue,i+1);
    if(i+1<n) result = max(result,stoneValue[i]+stoneValue[i+1] - solve(stoneValue,i+2));
    if(i+2<n) result = max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - solve(stoneValue,i+3));
    return dp[i] =  result;

}
public:
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        n = stoneValue.size();
        int diff = solve(stoneValue,0);
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
};