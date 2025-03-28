class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int xor_enc = 0;
        vector<int>ans;
        int n = encoded.size()+1;
        for(int i=0;i<encoded.size();i+=2){
            xor_enc^=encoded[i];
        }
        int xor_full = 0;
        for(int i=1;i<=n;i++) xor_full^=i;
        int ele = xor_full ^ xor_enc;
        ans.push_back(ele);
        for(int i=n-2;i>=0;i--){
            ele^=encoded[i];
            ans.push_back(ele);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};