class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start,int k , int n,vector<int>&v){
        if(v.size()==k){
            if(n==0) ans.push_back(v);
            return;
        }
        for(int i=start;i<=9;i++){
            v.push_back(i);
            solve(i+1,k,n-i,v);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(1,k,n,v);
        return ans;
    }
};
