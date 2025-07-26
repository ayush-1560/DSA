#include <vector>
#include <map> // Not strictly needed, but included in previous thought process. Can remove.
#include <numeric> // For std::gcd, which is not directly used in this problem, but in helper functions.
#include <cmath>   // For std::abs, not directly used here.
#include <algorithm> // For std::min, std::max, not directly used here.
#include <set>     // Not used in the final Segment Tree logic.

// Using __builtin_popcountll for efficiency to count set bits in a long long.
// This is a GCC/Clang extension. If compiling with MSVC, use __popcnt64.
// For general portability, a manual implementation is needed if compiler intrinsics are not allowed.
// For competitive programming, builtins are generally fine.
int get_popcount(long long n) {
    return __builtin_popcountll(n);
}

// Maximum possible popcount-depth based on constraints (k <= 5).
// Even for very large numbers (up to 10^15), the popcount sequence quickly converges to 1.
// 2^50 - 1 (approx 10^15) -> popcount=50
// 50 -> popcount=3
// 3 -> popcount=2
// 2 -> popcount=1
// So, max depth for x > 1 is actually 4. k=5 handles it.
const int MAX_DEPTH = 5; 

// Function to calculate the popcount-depth of a number x.
int get_popcount_depth(long long x) {
    if (x == 1) return 0; // Base case: depth 0 for 1.
    int depth = 0;
    long long current_val = x;
    while (current_val != 1) {
        current_val = get_popcount(current_val);
        depth++;
    }
    return depth;
}

class Solution {
private:
    // Inner class for the Segment Tree
    class SelfContainedSegmentTree {
    private:
        // `tree` stores the counts of numbers with each popcount-depth.
        // `tree[node_idx][d]` stores the count of numbers with popcount-depth `d`
        // in the range covered by `node_idx`.
        std::vector<std::vector<int>> tree;
        // `internal_nums` stores the actual numbers, allowing updates.
        std::vector<long long> internal_nums; 
        int n; // Size of the array `internal_nums`.

        // Helper function to combine depth counts from two child nodes.
        void combine(std::vector<int>& res, const std::vector<int>& left, const std::vector<int>& right) {
            for (int d = 0; d <= MAX_DEPTH; ++d) {
                res[d] = left[d] + right[d];
            }
        }

        // Builds the segment tree recursively.
        // `node_idx`: current node's index in the `tree` vector.
        // `start`, `end`: range of indices in `internal_nums` covered by this node.
        void build(int node_idx, int start, int end) {
            if (start == end) {
                // Leaf node: calculate depth for the single number and set its count.
                int depth = get_popcount_depth(internal_nums[start]);
                if (depth <= MAX_DEPTH) { 
                    tree[node_idx][depth] = 1;
                }
            } else {
                // Internal node: recursively build left and right children, then combine.
                int mid = start + (end - start) / 2; // Avoids potential overflow for (start+end)/2
                build(2 * node_idx, start, mid);
                build(2 * node_idx + 1, mid + 1, end);
                combine(tree[node_idx], tree[2 * node_idx], tree[2 * node_idx + 1]);
            }
        }

        // Updates a value at a specific index `idx` in the segment tree.
        // `node_idx`, `start`, `end`: current node's context.
        // `idx`: index in `internal_nums` to be updated.
        // `new_val`: the new value for `internal_nums[idx]`.
        void update_tree_recursive(int node_idx, int start, int end, int idx, long long new_val) {
            if (start == end) {
                // Found the leaf node corresponding to `idx`.
                internal_nums[idx] = new_val; // Update the number itself.
                
                // Reset all depth counts for this leaf.
                for(int d = 0; d <= MAX_DEPTH; ++d) {
                    tree[node_idx][d] = 0;
                }
                // Set the count for the new depth.
                int depth = get_popcount_depth(new_val);
                if (depth <= MAX_DEPTH) {
                    tree[node_idx][depth] = 1;
                }
            } else {
                // Traverse down to find the leaf node.
                int mid = start + (end - start) / 2;
                if (idx <= mid) { // `idx` is in the left child's range
                    update_tree_recursive(2 * node_idx, start, mid, idx, new_val);
                } else { // `idx` is in the right child's range
                    update_tree_recursive(2 * node_idx + 1, mid + 1, end, idx, new_val);
                }
                // After recursive call returns, re-combine children's data.
                combine(tree[node_idx], tree[2 * node_idx], tree[2 * node_idx + 1]);
            }
        }

        // Queries the segment tree for counts within a range [L, R].
        // `node_idx`, `start`, `end`: current node's context.
        // `L`, `R`: query range.
        std::vector<int> query_tree_recursive(int node_idx, int start, int end, int L, int R) {
            if (R < start || end < L) {
                // Current node's range is completely outside the query range. Return all zeros.
                return std::vector<int>(MAX_DEPTH + 1, 0);
            }
            if (L <= start && end <= R) {
                // Current node's range is completely inside the query range. Return its stored counts.
                return tree[node_idx];
            }
            // Partial overlap: query both children and combine results.
            int mid = start + (end - start) / 2;
            std::vector<int> p1 = query_tree_recursive(2 * node_idx, start, mid, L, R);
            std::vector<int> p2 = query_tree_recursive(2 * node_idx + 1, mid + 1, end, L, R);
            std::vector<int> res(MAX_DEPTH + 1);
            combine(res, p1, p2);
            return res;
        }

    public:
        // Constructor for the Segment Tree.
        // Takes the initial numbers by const reference and creates an internal copy.
        SelfContainedSegmentTree(const std::vector<long long>& initial_nums) {
            n = initial_nums.size();
            internal_nums = initial_nums; // Make a copy of the initial numbers.
            // Tree size: 4*N is a common safe upper bound for segment tree.
            tree.resize(4 * n, std::vector<int>(MAX_DEPTH + 1, 0));
            build(1, 0, n - 1); // Start building from the root (node 1).
        }

        // Public method to update a value.
        void update(int idx, long long val) {
            update_tree_recursive(1, 0, n - 1, idx, val);
        }

        // Public method to query for a specific depth `k` within a range `[l, r]`.
        int query(int l, int r, int k) {
            if (k > MAX_DEPTH || k < 0) return 0; // k is out of the supported depth range.
            std::vector<int> res_counts = query_tree_recursive(1, 0, n - 1, l, r);
            return res_counts[k];
        }
    };

public:
    std::vector<int> popcountDepth(std::vector<long long>& nums, std::vector<std::vector<long long>>& queries) {
        // Create an instance of the SelfContainedSegmentTree.
        // It will manage the `nums` data internally and its depths.
        SelfContainedSegmentTree seg_tree(nums); 

        std::vector<int> results; // To store the answers for type 1 queries.

        // Process each query.
        for (const auto& query : queries) {
            if (query[0] == 1) { // Type 1 query: [1, l, r, k]
                int l = static_cast<int>(query[1]);
                int r = static_cast<int>(query[2]);
                int k = static_cast<int>(query[3]);
                results.push_back(seg_tree.query(l, r, k));
            } else { // Type 2 query: [2, idx, val]
                int idx = static_cast<int>(query[1]);
                long long val = query[2]; // `val` is already long long.
                seg_tree.update(idx, val);
            }
        }
        return results;
    }
};