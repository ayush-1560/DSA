class Solution {
public:
    vector<vector<int>>ans;
    void solve(int start,int n, int k,vector<int>&v){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<=n;i++){
                v.push_back(i);
                solve(i+1,n,k,v);
                v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        solve(1,n,k,v);
        return ans;
    }
};