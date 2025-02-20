class LFUCache {
public:
    int cap,size;
    unordered_map<int,list<vector<int>>::iterator>mp;
    map<int,list<vector<int>>>freq;
    void MRU(int key){
        auto & vec = *(mp[key]);
        int value = vec[1];
        int f =  vec[2];
        freq[f].erase(mp[key]);
        if(freq[f].empty()) freq.erase(f);
        f++;
        freq[f].push_front({key,value,f});
        mp[key]=freq[f].begin();
    }
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        auto & vec = *(mp[key]);
        int value = vec[1];
        MRU(key);
        return value;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(mp.find(key)!=mp.end()){
            auto& vec = *(mp[key]);
            vec[1] = value;
            MRU(key);
        }
        else if (size < cap){
            size++;
            freq[1].push_front({key,value,1});
            mp[key] = freq[1].begin();
        }
        else{
            auto & list_to_del = freq.begin()->second;
            int key_to_del = list_to_del.back()[0];
            list_to_del.pop_back();
            if(list_to_del.empty()){
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front({key,value,1});
            mp.erase(key_to_del);
            mp[key] = freq[1].begin();
        }
    }
};

