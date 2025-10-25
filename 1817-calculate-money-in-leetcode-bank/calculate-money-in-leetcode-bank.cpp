class Solution {
public:
    int totalMoney(int n) {
        int n1 = n/7;
        int n2= n%7;
        int ans =0;
        ans+=n1*(2*28 + (n1-1)*7)/2;
        int sv = n1+1;
        for(int i=1;i<=n2;i++){
            ans+=sv;
            sv++;
        }
        return ans;
    }
};