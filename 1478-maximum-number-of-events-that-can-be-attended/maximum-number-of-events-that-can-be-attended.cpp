class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
            return a[1] < b[1];
        });
        set<int>days;
        for(int i=1;i<=1e5;i++) days.insert(i);
        int cnt =0;
        for(auto event : events){
            auto it = days.lower_bound(event[0]);
            if(it==days.end() || *it > event[1]) continue;
            else {
                cnt++;
                days.erase(it);
            }
        }
        return cnt;
    }
};