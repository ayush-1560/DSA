class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxRow=-1,minRow=m,maxCol=-1,minCol=n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxRow = max(maxRow,i);
                    minRow = min(minRow,i);
                    maxCol = max(maxCol,j);
                    minCol = min(minCol,j);
                }
            }
        }
        return (maxRow-minRow+1)*(maxCol-minCol+1);
    }
};