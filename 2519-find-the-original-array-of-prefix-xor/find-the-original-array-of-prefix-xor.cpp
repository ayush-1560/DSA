class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>ans(n);
        ans[0]=pref[0];
        int xor_running=0;
        for(int i=1;i<n;i++){
            xor_running^=ans[i-1];
            ans[i]=xor_running^pref[i];
        }
        return ans;
    }
};