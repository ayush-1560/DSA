class Solution {
public:
    unordered_set<int>foundBoxes;
    int dfs(int box,vector<int>&vis,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes){
        int ans=0;
        if(vis[box]) return 0;
        if(!status[box]){
            foundBoxes.insert(box);
            return 0;
        }
        vis[box] = true;
        ans+=candies[box];
        for(int insideBox : containedBoxes[box]){
            ans+=dfs(insideBox,vis,status,candies,keys,containedBoxes,initialBoxes);
        }
        for(int boxkey : keys[box]){
            status[boxkey]=1;
            if(foundBoxes.count(boxkey)) ans+=dfs(boxkey,vis,status,candies,keys,containedBoxes,initialBoxes);
        }
        return ans;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int ans = 0;
        vector<int>vis(n,false);
        for(int box : initialBoxes) ans+=dfs(box,vis,status,candies,keys,containedBoxes,initialBoxes);
        return ans;
    }
};