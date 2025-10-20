class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans  = 0;
        for(string op : operations) op[1] == '+' ? ans++ : ans--;
        return ans;
    }
};