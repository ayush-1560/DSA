class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (auto& domino : dominoes){
            if(domino[0]>domino[1]) swap(domino[0],domino[1]);
        }
        vector<int>mp(100,0);
        for(auto domino : dominoes){
            mp[domino[0]*10+domino[1]]++;
        }
        int ans =0;
        for(int i=0;i<100;i++){
            ans+=mp[i]*(mp[i]-1)/2;
        }
        return ans;
    }
};