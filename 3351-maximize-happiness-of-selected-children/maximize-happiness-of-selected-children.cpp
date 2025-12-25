class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans = 0;
        int i=0;
        int choosenCount=0;
        while(k-- && i<happiness.size()){
            int value = happiness[i] - choosenCount;
            ans+=max(0,value);
            choosenCount++;
            i++;
        }
        return ans;
    }
};