class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
       vector<vector<int>>mat(n,vector<int>(n,0));
       for(auto query : queries){
           int x1 = query[0];
           int y1 = query[1];
           int x2 = query[2];
           int y2 = query[3];
           for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                mat[i][j]++;
            }
           }
       }
       return mat; 
    }
};