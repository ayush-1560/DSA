class Solution {
public:
    bool solve(string &str) {
        int rem = 0;
        for (char c : str) {
            rem = (rem * 2 + (c - '0')) % 5;
        }
        return rem == 0;
    }

    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n, false);
        string temp = "";
        for (int i = 0; i < n; ++i) {
            temp += char('0' + nums[i]);
            ans[i] = solve(temp);
        }
        return ans;
    }
};
