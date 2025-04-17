class Solution {
public:
    vector<string> ans;

    void solve(int idx, string s, string temp) {
        if (idx == s.length()) {
            ans.push_back(temp);
            return;
        }

        if (isalpha(s[idx])) {
            solve(idx + 1, s, temp + (char)toupper(s[idx]));
            solve(idx + 1, s, temp + (char)tolower(s[idx]));
        } else {
            solve(idx + 1, s, temp + s[idx]);
        }
    }

    vector<string> letterCasePermutation(string s) {
        string temp = "";
        solve(0, s, temp);
        return ans;
    }
};
