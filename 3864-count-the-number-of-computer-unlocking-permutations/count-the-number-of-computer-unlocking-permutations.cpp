class Solution {
public:
    int MOD = 1e9+7;
    long long  fact(int n){
        long long f =1;
        for(int i=n;i>=1;i--) f = (f*i)%MOD;
        return f%MOD;
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[i] <= complexity[0]) return 0;
        }
        return fact(n-1)%MOD;
    }
};