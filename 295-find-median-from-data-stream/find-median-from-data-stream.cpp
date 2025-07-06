class MedianFinder {
public:
    priority_queue<int>maxH;
    priority_queue<int,vector<int>,greater<>>minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxH.empty() || num<maxH.top()) maxH.push(num);
        else minH.push(num);

        if((abs)((int)maxH.size() - (int)minH.size() > 1)){
            minH.push(maxH.top());
            maxH.pop();
        }
        else if(maxH.size() < minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if(minH.size()==maxH.size()){
            return (double) (minH.top() + maxH.top())/2.0;
        }
        else return maxH.top()/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */