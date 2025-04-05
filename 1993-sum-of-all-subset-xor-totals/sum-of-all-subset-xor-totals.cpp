class Solution {
public:
    int calculateXor(vector<int>& v){
        int XOR=0;
        for(auto ele : v) XOR^=ele;
        return XOR;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int subsets=1<<n;
        int ans=0;
        for(int num=0;num<subsets;num++){
            vector<int>v;
            for(int i=0;i<n;i++){
                if(num&(1<<i)){
                    v.push_back(nums[i]);
                }
            }
            ans+=calculateXor(v);
        }
        return ans;
    }
};