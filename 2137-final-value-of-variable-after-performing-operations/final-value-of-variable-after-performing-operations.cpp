class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans  = 0;
        for(string op : operations) op=="++X" || op=="X++" ? ans++ : ans--;
        return ans;
    }
};