class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>events;
        vector<vector<int>>ans;
        int prevMax=0;
        for(auto ele : buildings){
            events.push_back({ele[0],-ele[2]});
            events.push_back({ele[1],ele[2]});
        }
        sort(events.begin(),events.end());
        multiset<int>st = {0};
        for(auto event : events){
            if(event.second<0){
                st.insert(-event.second);
            }
            else st.erase(st.find(event.second));
            int currMax = *st.rbegin();
            if(currMax!=prevMax){
            ans.push_back({event.first,currMax});
            prevMax= currMax;
            }
        }
        return ans;
    }
};