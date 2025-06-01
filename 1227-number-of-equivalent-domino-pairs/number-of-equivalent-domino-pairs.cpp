class Solution {
public:
    
    int calc(int n){
        return n*(n-1)/2;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (auto& domino : dominoes){
            if(domino[0]>domino[1]) swap(domino[0],domino[1]);
        }
        unordered_map<string,int>mp;
        for(auto domino : dominoes) {
            string temp = to_string(domino[0]) + "_" + to_string(domino[1]);
            mp[temp]++;
        }
        int ans =0;
        for(auto it : mp){
            if(it.second>1) ans+=calc(it.second);
        }
        return ans;
    }
};