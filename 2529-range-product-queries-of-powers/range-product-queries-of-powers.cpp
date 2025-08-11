class Solution {
public:
    const int M = 1e9 + 7;
    int findPower(long long a, long long b) {
        if(b == 0)
            return 1;
        
        long long half = findPower(a, b/2);
        long long result = (half * half) % M;

        if(b%2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        for(int i=0;i<31;i++){
            if(n&(1<<i)) powers.push_back(1<<i);
        }
        vector<int>ans;
        vector<long long>prof(powers.size());
        prof[0]=powers[0]%M;
        for(int i=1;i<powers.size();i++){
            prof[i]=(prof[i-1]*powers[i])%M;
        }
        for(auto query : queries){
            int start = query[0];
            int end = query[1];
            if(start==0) ans.push_back(prof[end]);
            else{
                long long res = prof[end]* findPower(prof[start-1],M-2)%M;
                ans.push_back(res);
            }
        }
        return ans;
    }
};