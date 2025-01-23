class Solution {
public:
    
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int serverCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bool canComm=false;
                    for(int k=0;k<n;k++){
                        if(grid[i][k]==1 && k!=j){
                            serverCount++;
                            canComm=true;
                            break;
                        }
                    }
                    if(!canComm){
                        for(int t=0;t<m;t++){
                        if(grid[t][j]==1 && t!=i){
                            serverCount++;
                            break;
                        }
                    }
                    }
                }
            }
        }
        return serverCount;
    }
};