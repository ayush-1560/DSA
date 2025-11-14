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
                mat[i][y1]+=1;
                if(y2+1<n) mat[i][y2+1]-=1;
           }
       }
       for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            mat[i][j]+=mat[i][j-1];
        }
       }
       return mat; 
    }
};