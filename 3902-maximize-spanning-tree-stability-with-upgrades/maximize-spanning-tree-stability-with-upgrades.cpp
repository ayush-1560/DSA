#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionSet(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) {
            return false;
        }
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else {
            parent[yRoot] = xRoot;
            if (rank[xRoot] == rank[yRoot]) {
                rank[xRoot]++;
            }
        }
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> mustEdges;
        vector<vector<int>> optionalEdges;
        for (const auto& edge : edges) {
            if (edge[3] == 1) {
                mustEdges.push_back({edge[0], edge[1], edge[2]});
            } else {
                optionalEdges.push_back({edge[0], edge[1], edge[2]});
            }
        }
        
        UnionFind uf(n);
        int mustUsed = 0;
        for (const auto& edge : mustEdges) {
            if (uf.unionSet(edge[0], edge[1])) {
                mustUsed++;
            } else {
                return -1;
            }
        }
        
        int left = 1;
        int right = 0;
        for (const auto& edge : edges) {
            right = max(right, edge[2] * 2);
        }
        
        int answer = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            UnionFind ufCheck(n);
            bool possible = true;
            
            for (const auto& edge : mustEdges) {
                if (edge[2] < mid) {
                    possible = false;
                    break;
                }
                ufCheck.unionSet(edge[0], edge[1]);
            }
            if (!possible) {
                right = mid - 1;
                continue;
            }
            
            int upgradesUsed = 0;
            vector<vector<int>> edgesNoUpgrade;
            vector<vector<int>> edgesUpgrade;
            
            for (const auto& edge : optionalEdges) {
                if (edge[2] >= mid) {
                    edgesNoUpgrade.push_back(edge);
                } else if (edge[2] * 2 >= mid) {
                    edgesUpgrade.push_back(edge);
                }
            }
            
            for (const auto& edge : edgesNoUpgrade) {
                ufCheck.unionSet(edge[0], edge[1]);
            }
            
            for (const auto& edge : edgesUpgrade) {
                if (upgradesUsed >= k) {
                    break;
                }
                if (ufCheck.unionSet(edge[0], edge[1])) {
                    upgradesUsed++;
                }
            }
            
            int components = 0;
            for (int i = 0; i < n; ++i) {
                if (ufCheck.find(i) == i) {
                    components++;
                }
            }
            
            if (components == 1) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return answer;
    }
};