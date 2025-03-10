class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<>>pq;
        for(auto ele : nums) pq.push(ele);
        int ops =0;
        while(pq.size()>1 && pq.top()<k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            ops++;
            pq.push(x*2+y);
        }
        return ops;
    }
};