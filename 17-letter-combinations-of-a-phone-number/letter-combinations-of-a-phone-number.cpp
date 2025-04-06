class Solution {
public:
    vector<string>ans;
    unordered_map<char, string> mp = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    {'8', "tuv"}, {'9', "wxyz"}
};
    void solve(int idx,string digits,string temp){
        if(idx>=digits.size()){
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(idx+1,digits,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        if(digits.empty()) return ans;
        solve(0,digits,temp);
        return ans;
    }
};