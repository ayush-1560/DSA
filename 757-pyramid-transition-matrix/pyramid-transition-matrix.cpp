class Solution {
public:
    unordered_map<string,bool>dp;
    bool solve(string curr,unordered_map<string,vector<char>>&mp,int idx,string above ){
        if(curr.length()==1) return true;
        string key = curr + "_" + to_string(idx) + "_" + above;
        if(dp.count(key)) return dp[key];
        if(idx+1==curr.length()){
            return dp[key] =  solve(above,mp,0,"");
        }
        string pair = curr.substr(idx,2);
        if(!mp.count(pair)) return false;
        for(char & ch : mp[pair]){
            above.push_back(ch);
            if(solve(curr,mp,idx+1,above)) return true;
            above.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mp;
        for(auto pattern : allowed){
            mp[pattern.substr(0,2)].push_back(pattern[2]);
        }
        return solve(bottom,mp,0,"");
    }
};