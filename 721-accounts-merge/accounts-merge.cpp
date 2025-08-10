class Solution {
public:
    vector<int> parent, rank;

    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);
        if (par_x == par_y) return;
        if (rank[par_x] > rank[par_y]) {
            parent[par_y] = par_x;
        } else if (rank[par_y] > rank[par_x]) {
            parent[par_x] = par_y;
        } else {
            parent[par_y] = par_x;
            rank[par_x]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        rank.assign(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<string, int> mp;

        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string& mail = accounts[i][j];
                if (!mp.count(mail)) {
                    mp[mail] = i;
                } else {
                    Union(i, mp[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for (auto& it : mp) {
            string mail = it.first;
            int node = find(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), mergedMail[i].begin(), mergedMail[i].end());
            ans.push_back(temp);
        }

        return ans;
    }
};
