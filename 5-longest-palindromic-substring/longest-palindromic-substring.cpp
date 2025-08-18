class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1;
        int sp = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;

                if (s[i] == s[j]) {
                    if (L == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }

                    if (dp[i][j] && L > maxLen) {
                        maxLen = L;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};
