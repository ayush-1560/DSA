class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondRemSum=0;
        long long ans = LONG_LONG_MAX;
        for(int j=0;j<grid[0].size();j++){
            firstRowSum-=grid[0][j];
            long long robot2Choice = max(firstRowSum,secondRemSum);
            ans= min(robot2Choice,ans);
            secondRemSum+=grid[1][j];
        } 
        return ans;
    }
};