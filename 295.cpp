class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {  
    }
    
    void addNum(int num) {
        double median = findMedian();
        if (num < median) {
            smaller.insert(num);
        } else {
            bigger.insert(num);
        }
        adjustNumSet();
    }
    
    double findMedian() {
        int size = smaller.size() + bigger.size();
        if (size == 0) {
            return MAX_INT;
        }
        if (size & 1) {
            return *smaller.rbegin();
        } else {
            return static_cast<double>(*smaller.rbegin() + *bigger.begin()) / 2;
        }
    }
private:
    const int MAX_INT = ~0u >> 1;
    multiset<int> smaller, bigger;
    
    void adjustNumSet() {
        while (smaller.size() > bigger.size() + 1) {
            int num = *smaller.rbegin();
            auto it = smaller.end();
            --it;
            smaller.erase(it);
            bigger.insert(num);
        }
        while (smaller.size() < bigger.size()) {
            int num = *bigger.begin();
            bigger.erase(bigger.begin());
            smaller.insert(num);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */