class Solution {
public:
    int n;
    int dp[2001][2001];
    bool solve(int curr_idx, int prev,unordered_map<int,int>&mp,vector<int>& stones){
        if(curr_idx==n-1) return true;
        if(dp[curr_idx][prev]!=-1) return dp[curr_idx][prev];
        bool ans = false;
        for(int nextJump=prev-1;nextJump<=prev+1;nextJump++){
            if(nextJump > 0){
                int nextStone = stones[curr_idx] + nextJump;
                if(mp.count(nextStone)){
                    ans = ans || solve(mp[nextStone],nextJump,mp,stones);
                }
            }
        }
        return dp[curr_idx][prev] = ans;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        memset(dp,-1,sizeof(dp));
        unordered_map<int,int>mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        return solve(0,0,mp,stones);
    }
};