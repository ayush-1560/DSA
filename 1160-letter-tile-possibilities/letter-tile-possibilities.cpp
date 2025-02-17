class Solution {
public:
    void solve(string tiles,string curr,vector<bool>&used,unordered_set<string>&ans){
        ans.insert(curr);
        for(int i=0;i<tiles.length();i++){
            if(used[i]) continue;
            used[i]=true;
            curr.push_back(tiles[i]);
            solve(tiles,curr,used,ans);
            used[i]=false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        vector<bool>used(tiles.length(),false);
        unordered_set<string>ans;
        solve(tiles,"",used,ans);
        return ans.size()-1;
    }
};