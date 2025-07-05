class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P>pq;
        for(auto point : points){
            int dis =(point[0]*point[0] + point[1]*point[1]);
            pq.push({dis,{point[0],point[1]}});
            while(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};