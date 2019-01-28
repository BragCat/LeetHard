class SegTreeNode {
private:
    int cnt, left, right, maxCnt;
    SegTreeNode *lson, *rson;
public:
    SegTreeNode(int l, int r): cnt(0), maxCnt(0), left(l), right(r), lson(nullptr), rson(nullptr) {}
    
    SegTreeNode *getLson() {
        if (!lson) {
            lson = new SegTreeNode(left, left + (right - left) / 2);
        }
        return lson;
    }
    
    SegTreeNode *getRson() {
        if (!rson) {
            rson = new SegTreeNode(left + (right - left) / 2, right);
        }
        return rson;
    }
    
    void addValue(int l, int r, int v) {
        if (l <= left && r >= right) {
            cnt += v;
            maxCnt += v;
            return;
        }
        if (r <= left || l >= right) {
            return;
        }
        getLson()->addValue(l, r, v);
        getRson()->addValue(l, r, v);
        maxCnt = max(lson->maxCnt, rson->maxCnt) + cnt;
    }
    
    int getMaxValue(int l, int r) {
        if (l <= left && r >= right) {
            return maxCnt;
        }
        if (r <= left && l >= right) {
            return 0;
        }
        return max(getLson()->getMaxValue(l, r), getRson()->getMaxValue(l, r)) + cnt;
    }
};

class MyCalendarThree {
public:
    MyCalendarThree() {
        root = new SegTreeNode(0, 1e9);
    }
    
    int book(int start, int end) {
        root->addValue(start, end, 1);
        return root->getMaxValue(0, 1e9);
    }
private:
    SegTreeNode *root;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */