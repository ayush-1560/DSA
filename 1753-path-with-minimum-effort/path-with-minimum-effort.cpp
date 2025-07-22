class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        auto isSafe = [&](int x, int y){
            return (x>=0 && x<m && y>=0 && y<n);
        };
        ans[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(auto dir : directions){
                int x_ = x + dir[0];
                int y_ = y+ dir[1];
                if(isSafe(x_,y_)){
                    int absDiff = abs(heights[x_][y_] - heights[x][y]);
                    int maxDiff = max(diff,absDiff);
                    if(ans[x_][y_] > maxDiff){
                        ans[x_][y_] = maxDiff;
                        pq.push({maxDiff,{x_,y_}});
                    }
                }
            }
        }
        return ans[m-1][n-1];
    }
};