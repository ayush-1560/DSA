class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i, int j,vector<vector<char>>& board,vector<vector<bool>>&vis){
        vis[i][j] = true;
        for(auto dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && board[ni][nj]=='O' && !vis[ni][nj]) dfs(ni,nj,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='O') dfs(i,j,board,vis);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};