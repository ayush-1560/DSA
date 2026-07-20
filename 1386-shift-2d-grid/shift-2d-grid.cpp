class Solution {
void reverse(vector<vector<int>>& grid,int i, int j){
    int col = grid[0].size();
    while(i<j){
        swap(grid[i/col][i%col],grid[j/col][j%col]);
        i++;
        j--;
    }
}
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size()*grid[0].size();
        k=k%n;
        reverse(grid,0,n-1);
        reverse(grid,0,k-1);
        reverse(grid,k,n-1);
        
        return grid;
    }
};