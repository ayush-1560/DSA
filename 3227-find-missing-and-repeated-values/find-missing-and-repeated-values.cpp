class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int>mp;
        int a=0,b=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        for(auto it : mp) if(it.second==2) a=it.first;
        for(int i=1;i<=n*n;i++){
            if(mp.count(i)==0) b=i;
        }
        return {a,b};
    }
};