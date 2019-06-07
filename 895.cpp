struct CntIndValIter {
    int cnt, ind, val;
    list<int>::iterator iter;
    CntIndValIter(int cnt, int ind, int val, list<int>::iterator iter): cnt(cnt), ind(ind), val(val), iter(iter) {}
};
bool operator < (const CntIndValIter &x, const CntIndValIter &y) {
    return x.cnt < y.cnt || x.cnt == y.cnt && x.ind < y.ind;
}
class FreqStack {
public:
    FreqStack() {
        index = 0;
    }
    
    void push(int x) {
        stack.push_back(x);
        ++freqCnt[x];
        auto iter = stack.end();
        --iter;
        heap.push(CntIndValIter(freqCnt[x], index, x, iter));
        ++index;
    }
    
    int pop() {
        auto t = heap.top();
        heap.pop();
        stack.erase(t.iter);
        --freqCnt[t.val];
        return t.val;
    }
private:
    list<int> stack;
    priority_queue<CntIndValIter> heap;
    unordered_map<int, int> freqCnt;
    int index;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */