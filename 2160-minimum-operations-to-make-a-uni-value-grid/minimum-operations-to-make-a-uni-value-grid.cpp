class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        int s = v.size();
        nth_element(v.begin(),v.begin()+s/2,v.end());
        int ans =0;
        int target = v[s/2];
        for(auto ele : v){
            if(ele%x!=target%x) return -1;
            ans+=abs(ele-target)/x;
        }
        return ans;
    }
};