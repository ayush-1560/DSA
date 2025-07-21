class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int Find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = Find(parent[i]);
    }

    void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if (px == py) return;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; ++i) parent[i] = i;
        for (const string& eq : equations) {
            if (eq[1] == '=') {
                Union(eq[0] - 'a', eq[3] - 'a');
            }
        }

        for (const string& eq : equations) {
            if (eq[1] == '!') {
                if (Find(eq[0] - 'a') == Find(eq[3] - 'a')) return false;
            }
        }

        return true;
    }
};
