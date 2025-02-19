class MyHashMap {
public:
    vector<list<pair<int, int>>> buckets;
    int M;

    int getIdx(int key) {
        return key % M;
    }

    MyHashMap() {
        M = 15000;
        buckets.resize(M);
    }

    void put(int key, int value) {
        int idx = getIdx(key);
        auto& location = buckets[idx];
        for (auto& it : location) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        location.emplace_back(key, value);
    }

    int get(int key) {
        int idx = getIdx(key);
        auto& location = buckets[idx];
        for (auto& it : location) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int idx = getIdx(key);
        auto& location = buckets[idx];
        for (auto it = location.begin(); it != location.end();) {
            if (it->first == key) {
                it = location.erase(it);
            } else {
                it++; 
            }
        }
    }
};
