class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto& it : mp){
            if(it.first>=0) sort(it.second.rbegin(),it.second.rend());
            else sort(it.second.begin(),it.second.end());
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                grid[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};