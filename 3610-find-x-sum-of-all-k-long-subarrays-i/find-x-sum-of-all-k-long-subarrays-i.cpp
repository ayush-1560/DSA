class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        int i = 0, j = k - 1;

        while (j < n) {
            map<int, int> mp;
            for (int t = i; t <= j; t++) mp[nums[t]]++;

            if (mp.size() < x) {
                int sum = 0;
                for (auto &p : mp) sum += p.first * p.second;
                ans[i] = sum;
            } else {
                vector<pair<int,int>> freq;
                for (auto &p : mp) freq.push_back(p);
                sort(freq.begin(), freq.end(), [](auto &a, auto &b){
                    if (a.second == b.second) return a.first > b.first;
                    return a.second > b.second;
                });

                int sum = 0;
                for (int t = 0; t < x; t++) {
                    sum += freq[t].first * freq[t].second;
                }
                ans[i] = sum;
            }

            i++;
            j++;
        }

        return ans;
    }
};
