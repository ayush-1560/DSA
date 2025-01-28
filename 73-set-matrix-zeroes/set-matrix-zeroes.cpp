class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       vector<bool>markRows(m,false);
       vector<bool>markCols(n,false);
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                markRows[i]=true;
                markCols[j]=true;
            }
        }
       }
       for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(markRows[i] || markCols[j]) matrix[i][j]=0;
          }
       }
    }
};