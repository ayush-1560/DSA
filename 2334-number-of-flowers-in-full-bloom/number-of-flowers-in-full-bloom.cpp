class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        vector<int>startTime(m);
        vector<int>endTime(m);
        vector<int>ans(n);
        for(int i=0;i<m;i++){
            startTime[i]=flowers[i][0];
            endTime[i]=flowers[i][1];
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());
        for(int i=0;i<n;i++){
            int flower_bloomed = upper_bound(startTime.begin(),startTime.end(),people[i]) - startTime.begin();
            int flower_died = lower_bound(endTime.begin(),endTime.end(),people[i]) - endTime.begin();
            ans[i] = flower_bloomed - flower_died;
        }
        return ans;
    }
};