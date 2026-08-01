class Solution {
int dp[21][21];
int solve(vector<int>& nums,int i, int j){
    if(i>j) return 0;
    if(i==j) return nums[i];
    if(dp[i][j]!=-1) return dp[i][j];
    int take_i = nums[i] + min(solve(nums,i+2,j),solve(nums,i+1,j-1));
    int take_j = nums[j] + min(solve(nums,i+1,j-1),solve(nums,i,j-2));
    return dp[i][j] = max(take_i,take_j);
}
public:
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int totalScore = accumulate(nums.begin(),nums.end(),0);
        int player1Score = solve(nums,0,nums.size()-1);
        int player2Score = totalScore - player1Score;
        return player1Score >= player2Score;
    }
};