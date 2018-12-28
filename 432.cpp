class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto keyIterIt = keyIters.find(key);
        if (keyIterIt == keyIters.end()) {
            if (linkedList.empty() || linkedList.back().count() != 1) {
                linkedList.push_back(Bucket(1));
            }
            linkedList.back().insertKey(key);
            keyIters[key] = linkedList.end();
            --keyIters[key];
        } else {
            auto it = keyIterIt->second;
            int count = it->count();
            it->eraseKey(key);
            ++count;
            decltype(it) nowIt;
            if (it == linkedList.begin()) {
                linkedList.push_front(Bucket(count));
                nowIt = linkedList.begin();
            } else {
                auto prevIt = it;
                --prevIt;
                if (prevIt->count() != count) {
                    nowIt = linkedList.insert(it, Bucket(count));
                } else {
                    nowIt = prevIt;
                }
            }
            nowIt->insertKey(key);
            keyIters[key] = nowIt;
            if (it->size() == 0) {
                linkedList.erase(it);
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto keyIterIt = keyIters.find(key);
        if (keyIterIt == keyIters.end()) {
            return;
        }
        auto it = keyIterIt->second;    
        int count = it->count();
        it->eraseKey(key);
        --count;
        auto nextIt = it;
        ++nextIt;
        decltype(it) nowIt;
        if (it->size() == 0) {
            linkedList.erase(it);
        }
        if (count > 0) {
            if (nextIt == linkedList.end() || nextIt->count() != count) {
                nowIt = linkedList.insert(nextIt, Bucket(count));
            } else {
                nowIt = nextIt;
            }
            nowIt->insertKey(key);
            keyIters[key] = nowIt;
        } else {
            keyIters.erase(keyIterIt);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (linkedList.empty()) {
            return "";
        } else {
            return linkedList.front().getOneKey();
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (linkedList.empty()) {
            return "";
        } else {
            return linkedList.back().getOneKey();
        }
    }
private:
    class Bucket {
    public:
        Bucket(int count): _count(count) {}
        int count() {
            return _count;
        }
        void insertKey(string key) {
            keys.insert(key);
        }
        void eraseKey(string key) {
            keys.erase(key);
        }
        int size() {
            return keys.size();
        }
        string getOneKey() {
            return *keys.begin();
        }
    private:
        unordered_set<string> keys;
        int _count;
    };
    list<Bucket> linkedList;
    unordered_map<string, decltype(linkedList.begin())> keyIters; 
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */