class Solution {
void reverse(vector<int>&arr,int i, int j){
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void rotate(vector<int>&arr,int k){
    int n = arr.size();
    if(k==0) return;
    k = k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
}
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>arr;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]);
            }
        }

        rotate(arr,k);
        int t = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = arr[t];
                t++;
            }
        }

        return grid;
    }
};