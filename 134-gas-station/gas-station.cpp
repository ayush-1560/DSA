class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)) return -1;
        int ans = 0;
        int totalGas =0;
        for(int i=0;i<gas.size();i++){
            totalGas+=gas[i]-cost[i];
            if(totalGas < 0){
                totalGas=0;
                ans=i+1;
            }
        }
        return ans;
    }
};