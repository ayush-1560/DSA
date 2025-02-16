class Solution {
public:
    bool solve(int idx, int n, vector<int>& ans, vector<bool>& used) {
    if(idx >= ans.size()) return true;
    if(ans[idx] != -1) return solve(idx + 1, n, ans, used);
    
    for(int num = n; num >= 1; num--) {
        if(!used[num]) {
            used[num] = true;
            ans[idx] = num;
            
            if(num == 1) {
                if(solve(idx + 1, n, ans, used)) return true;
            } else {
                int j = idx + num;
                if(j < ans.size() && ans[j] == -1) {
                    ans[j] = num;
                    if(solve(idx + 1, n, ans, used)) return true;
                    ans[j] = -1;
                }
            }
            
            used[num] = false;
            ans[idx] = -1;
        }
    }
    
    return false;
}
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n-1,-1);
        vector<bool>used(n+1,false);
        solve(0,n,ans,used);
        return ans;
    }
};