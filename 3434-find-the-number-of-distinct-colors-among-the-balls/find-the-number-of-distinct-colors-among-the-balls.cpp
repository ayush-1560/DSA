class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int,int>balls;
        vector<int>ans(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int ball = queries[i][0];
            int color= queries[i][1];
            if(balls[ball]!=0){
                mp[balls[ball]]--;
                if(mp[balls[ball]]==0) mp.erase(balls[ball]);
            }
            balls[ball] = color;
            mp[color]++; 
            ans[i]=mp.size();
        }
        return ans;
    }
};