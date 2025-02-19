class MyHashMap {
public:
    vector<int>nums;
    MyHashMap() {
        nums.resize(10000001,-1);
    }
    
    void put(int key, int value) {
        nums[key]=value;
    }
    
    int get(int key) {
         if(nums[key]==-1) return -1;
         return nums[key];
    }
    
    void remove(int key) {
        nums[key]=-1;
    }
};
