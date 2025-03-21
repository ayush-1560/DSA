class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        vector<string> ans;
        int n = recipes.size();
        vector<bool>isCooked(n,false);
        int count = n;
        while(count--){
             for(int i = 0; i < n; i++){
                if(isCooked[i]) continue;
                string recipe = recipes[i];
                int sz = ingredients[i].size();
            
                for (string& item : ingredients[i]) {
                if (supplySet.find(item) != supplySet.end()) {
                    sz--;
                }
            }
            
            if (sz == 0) {
                supplySet.insert(recipe);
                ans.push_back(recipe);
                isCooked[i]=true;
            }
            }
        }
        return ans;
    }
};
