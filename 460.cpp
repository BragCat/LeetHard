class LFUCache {
public:
    LFUCache(int capacity): capacity(capacity), size(0) {
    }
    
    int get(int key) {
        int index = findIndex(key);
        if (index == -1) {
            return -1;
        } else {
            int value = kvs[index].second;
            int cnt = count[index] + 1;
            removeAtIndex(index);
            --size;
            insertKV(key, value, cnt);
            return value;
        }
    }
    
    void put(int key, int value) {
        int index = findIndex(key);
        int cnt = 1;
        if (index != -1) {
            cnt += count[index];
            removeAtIndex(index);
            --size;
        }
        insertKV(key, value, cnt);
    }
private:
    deque<pair<int, int>> kvs;
    deque<int> count;
    int size, capacity;
    
    int findIndex(int key) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (kvs[i].first == key) {
                index = i;
                break;
            }
        }
        return index;
    }
    
    void removeAtIndex(int index) {
        kvs.erase(kvs.begin() + index);
        count.erase(count.begin() + index);
    }
    
    void insertKV(int key, int value, int cnt) {
        if (size == capacity) {
            kvs.pop_front();
            count.pop_front();
            --size;
        }
        int nextIndex = size;
        for (int i = 0; i < size; ++i) {
            if (count[i] > cnt) {
                nextIndex = i;
                break;
            }
        }
        kvs.insert(kvs.begin() + nextIndex, make_pair(key, value));
        count.insert(count.begin() + nextIndex, cnt);
        ++size;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */