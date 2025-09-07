class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2) {
            ans.push_back(0);
            n--;
        }
        int x = 1;
        for(int i=1;i<=n/2;i++){
            ans.push_back(x);
            ans.push_back(-x);
            x++;
        }
        return ans;
    }
};