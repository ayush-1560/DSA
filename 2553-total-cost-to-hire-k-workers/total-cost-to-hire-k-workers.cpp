class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost =0;
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        int i=0,j=n-1;
        while(k--){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j--]);
            }
            int min_pq1=pq1.empty() ? INT_MAX : pq1.top();
            int min_pq2=pq2.empty() ? INT_MAX : pq2.top();
            if(min_pq1 <=min_pq2){
                cost+=min_pq1;
                pq1.pop();
            }
            else {
                cost+=min_pq2;
                pq2.pop();
            }
        }
        return cost;
    }
};