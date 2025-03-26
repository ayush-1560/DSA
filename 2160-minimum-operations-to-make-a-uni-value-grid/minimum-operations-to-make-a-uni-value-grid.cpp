class Solution {
public:
    int findAns(vector<int>&v,int idx,int x){
        int ans=0;
        for(int i=0;i<v.size();i++){
            int diff = abs(v[idx]-v[i]);
            if(diff%x!=0) return -1;
            ans+=diff/x;
        }
        return ans;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int s = v.size();
        return findAns(v,s/2,x);
    }
};