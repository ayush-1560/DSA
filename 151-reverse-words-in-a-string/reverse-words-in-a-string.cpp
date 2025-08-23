class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        stringstream ss(s);
        string word;
        while(ss >> word){
            v.push_back(word);
        }
        string ans;
        reverse(v.begin(),v.end());
        for(auto str : v){
            ans = ans + str + " ";
        }
        ans.pop_back();
        return ans;
    }
};