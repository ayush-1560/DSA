class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string>ans;
        unordered_set<string>st(supplies.begin(),supplies.end());
        unordered_map<string,vector<int>>adj;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(string& indg : ingredients[i]){
                if(!st.count(indg)){
                    adj[indg].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            string recipe = recipes[i];
            ans.push_back(recipe);
            for(int& x : adj[recipe]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        return ans;
    }
};