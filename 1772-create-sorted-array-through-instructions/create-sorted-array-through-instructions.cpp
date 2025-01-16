#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
        ordered_multiset ms;
        int MOD = 1e9 + 7;
        long long cost = 0;

        for (int i = 0; i < instructions.size(); i++) {
            int x = instructions[i];
            int smaller = ms.order_of_key(x);
            int larger = ms.size() - ms.order_of_key(x + 1);
            cost = (cost + min(smaller, larger)) % MOD;
            ms.insert(x);
        }

        return cost;
    }
};
