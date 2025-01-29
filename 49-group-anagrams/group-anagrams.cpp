class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto str : strs){
            string lexo = str;
            sort(lexo.begin(),lexo.end());
            if(mp.find(lexo)==mp.end()){
                mp[lexo] = {str};
            }
            else mp[lexo].push_back(str);
        }
        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};