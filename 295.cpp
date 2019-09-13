class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        small_cnt = big_cnt = 0;
    }
    
    void addNum(int num) {
        double median = findMedian();
        if (num <= median) {
            small_nums.insert(num);
            ++small_cnt;
        } else {
            big_nums.insert(num);
            ++big_cnt;
        }
        if (small_cnt < big_cnt) {
            small_nums.insert(*big_nums.begin());
            big_nums.erase(big_nums.begin());
            ++small_cnt;
            --big_cnt;
        } else if (small_cnt > big_cnt + 1){
            big_nums.insert(*small_nums.begin());
            small_nums.erase(small_nums.begin());
            --small_cnt;
            ++big_cnt;
        }
    }
    
    double findMedian() {
        if (small_cnt > big_cnt) {
            return *small_nums.begin();
        } else if (small_cnt > 0) {
            return (*small_nums.begin() + *big_nums.begin()) / 2.0;
        } else {
            return MAX_INT;
        }
    }
private:
    const int MAX_INT = ~0u >> 1;
    multiset<int, greater<int>> small_nums;
    multiset<int> big_nums;
    int small_cnt, big_cnt;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */