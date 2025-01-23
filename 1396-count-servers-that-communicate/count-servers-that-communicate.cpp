class Solution {
public:
    
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>rowCount(m,0);
        vector<int>colCount(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) rowCount[i]++;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(grid[i][j]==1) colCount[j]++;
            }
        }
        int serverCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(rowCount[i] > 1 || colCount[j]>1) serverCount++;
                }
            }
        }
        return serverCount;
    }
};