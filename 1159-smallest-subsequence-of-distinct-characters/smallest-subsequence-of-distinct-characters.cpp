class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> lastIdx(26, -1);
        vector<bool> taken(26, false);

        for (int i = 0; i < n; i++)
            lastIdx[s[i] - 'a'] = i;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if(taken[s[i]-'a']) continue;
            while (!ans.empty() && s[i] < ans.back() &&
                   lastIdx[ans.back() - 'a'] > i) {

                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += s[i];
            taken[s[i] - 'a'] = true;
        }
        return ans;
    }
};