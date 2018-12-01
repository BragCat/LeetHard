class LRUCache {
public:
    LRUCache(int capacity): capacity(capacity), size(0) {
    }
    
    int get(int key) {
        for (int i = 0; i < size; ++i) {
            if (cache[i].first == key) {
                int value = cache[i].second;
                cache.erase(cache.begin() + i); 
                cache.emplace_back(key, value);
                return value;
            } 
        }    
        return -1;
    }
    
    void put(int key, int value) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (cache[i].first == key) {
                index = i;
                break; 
            }
        }
        if (index == -1) {
            if (size == capacity) {
                cache.pop_front();
                cache.emplace_back(key, value); 
            } else {
                cache.emplace_back(key, value);
                size++;
            }
        } else {
            cache.erase(cache.begin() + index); 
            cache.emplace_back(key, value);
        }
    }

private:
    deque<pair<int ,int>> cache;
    int size, capacity;
};
