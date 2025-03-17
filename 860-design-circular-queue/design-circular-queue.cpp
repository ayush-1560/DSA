class MyCircularQueue {
public:
    vector<int>q;
    int front,rear,size;
    MyCircularQueue(int k) {
        q = vector<int>(k,-1);
        front=rear=0;
        size=0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            front=rear=0;
            q[rear]=value;
            size++;
            return true;
        }
        rear++;
        size++;
        rear = rear%q.size();
        q[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        q[front] = -1;
        front++;
        size--;
        front=front%q.size();
        return true;
    }
    
    int Front() {
        return q[front];
    }
    
    int Rear() {
        return q[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==q.size();
    }
};
