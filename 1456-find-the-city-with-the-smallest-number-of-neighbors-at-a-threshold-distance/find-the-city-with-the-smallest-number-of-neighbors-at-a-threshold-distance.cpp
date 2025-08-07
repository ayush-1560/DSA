class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) mat[i][i] = 0;
        for (auto& edge : edges) {
            mat[edge[0]][edge[1]] = edge[2];
            mat[edge[1]][edge[0]] = edge[2];
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j)
                    if(mat[i][via]<1e8 && mat[via][j]<1e8){
                        mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                    }
                }
            }
        }
        int minCnt=n,maxCity=0;
        for(int i=0;i<n;i++){
            int currCnt=0;
            for(int num : mat[i]){
                if(num<=threshold) {
                    currCnt++;
                }
            }
            if(minCnt>=currCnt){
                minCnt=currCnt;
                maxCity=i;
            }
        }
        return maxCity;;
    }
};