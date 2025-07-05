class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int K;
    void insert(int val){
        pq.push(val);
        if(pq.size()>K) pq.pop();
    }
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int val : nums) insert(val);
    }
    
    int add(int val) {
        insert(val);
        return pq.top();
    }
};
