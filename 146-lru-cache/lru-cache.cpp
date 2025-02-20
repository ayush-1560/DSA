class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int n;
    void MRU(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        MRU(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            MRU(key);
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(),value};
            n--;
        }
        if(n<0){
            int key_idx = dll.back();
            mp.erase(key_idx);
            dll.pop_back();
            n++;
        }
    }
};
