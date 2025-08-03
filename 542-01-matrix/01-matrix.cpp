class Solution {
public:
    vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto dir : directions){
                    int i_= i + dir[0];
                    int j_ = j + dir[1];
                    if(i_>=0 && i_<m && j_>=0 && j_<n && ans[i_][j_]==-1){
                        ans[i_][j_] = ans[i][j]+1;
                        q.push({i_,j_});
                    }
                }
            }
        }
        return ans; 
    }
};