class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        int n = 2;
        while(n<numRows+1){
            vector<int>v(n);
            v[0]=v[n-1]=1;
            for(int i=1;i<=n-2;i++){
                v[i]=ans.back()[i-1] + ans.back()[i];
            }
            ans.push_back(v);
            n++;
        }
        return ans;
    }
};