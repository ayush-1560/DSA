class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(string str : strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            if(mp.count(temp)){
                mp[temp].push_back(str);
            }
            else mp.insert({temp,{str}});
        }
        for(auto it : mp){
            vector<string>v;
            for(string str : it.second) v.push_back(str);
            ans.push_back(v);
        }
        return ans;
    }
};