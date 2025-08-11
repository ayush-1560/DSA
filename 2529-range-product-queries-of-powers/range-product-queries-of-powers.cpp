class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        for(int i=0;i<31;i++){
            if(n&(1<<i)) powers.push_back(1<<i);
        }
        vector<int>ans;
        for(auto query : queries){
            int start = query[0];
            int end = query[1];
            long long prod = 1;
            for(int i=start;i<=end;i++){
                prod=(prod*powers[i])%MOD;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};