class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<pair<int,pair<int,int>>>dis;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dis.push_back({abs(rCenter-i) + abs(cCenter-j)
                ,{i,j}});
            }
        }
        sort(dis.begin(),dis.end());
        vector<vector<int>>ans;
        for(auto ele : dis){
            ans.push_back({ele.second.first,ele.second.second});
        }
        return ans;
    }
};