class FreqStack {
public:
    unordered_map<int,int>mp;
    priority_queue<tuple<int,int,int>>pq;
    int timeStamp;
    FreqStack() {
       timeStamp=0; 
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],timeStamp++,val});
    }
    
    int pop() {
        auto [_,_,ele]=pq.top();
        pq.pop();
        mp[ele]--;
        return ele;
    }
};
