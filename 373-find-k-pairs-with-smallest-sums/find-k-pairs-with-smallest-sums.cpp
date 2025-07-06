class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        set<pair<int,int>>visited;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        while(!pq.empty() && k--){
            auto ele = pq.top();
            pq.pop();
            int i= ele.second.first;
            int j = ele.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<nums1.size()){
              if(!visited.count({i+1,j})) pq.push({nums1[i+1]+nums2[j],{i+1,j}});
              visited.insert({i+1,j});
            } 
            if(j+1<nums2.size()){
                if(!visited.count({i,j+1})) pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            } 
        }
        return ans;
    }
};