class SegmentNode {
public:
    SegmentNode(int left, int right, bool tracked): left(left), right(right), tracked(tracked) {
        lson = rson = nullptr;
    }
    
    ~SegmentNode() {
        removeNode(this->lson);
        removeNode(this->rson);
    }
    
    bool setRangeState(int left, int right, bool tracked) {
        if (right <= this->left || left >= this->right) {
            return this->tracked;
        }
        if (left <= this->left && right >= this->right) {
            removeNode(this->lson);
            removeNode(this->rson);
            return this->tracked = tracked;
        }
        bool lState = this->getLson()->setRangeState(left, right, tracked);
        bool rState = this->getRson()->setRangeState(left, right, tracked);
        return this->tracked = lState && rState;
    }
    
    bool queryRangeState(int left,  int right) {
        if (right <= this->left || left >= this->right) {
            return true;
        }
        if (left <= this->left && right >= this->right) {
            return this->tracked;
        }
        return this->getLson()->queryRangeState(left, right) && this->getRson()->queryRangeState(left, right);
    }
    
    static void removeNode(SegmentNode * &node) {
        if (node) {
            removeNode(node->lson);
            removeNode(node->rson);
            delete node;
            node = nullptr;
        }
    }
    
private:
    bool tracked;
    int left, right;
    SegmentNode *lson, *rson;
    
    int getMid() {
        return left + (right - left) / 2;
    }
    
    SegmentNode *getLson() {
        if (!lson) {
            lson = new SegmentNode(left, getMid(), tracked);
        }
        return lson;
    }
    
    SegmentNode *getRson() {
        if (!rson) {
            rson = new SegmentNode(getMid(), right, tracked); 
        }
        return rson;
    }
};

class RangeModule {
public:
    RangeModule() {
        root = new SegmentNode(0, 1e9, false);
    }
    
    ~RangeModule() {
        SegmentNode::removeNode(root);
    }
    
    void addRange(int left, int right) {
        root->setRangeState(left, right, true);
    }
    
    bool queryRange(int left, int right) {
        return root->queryRangeState(left, right);
    }
    
    void removeRange(int left, int right) {
        root->setRangeState(left, right, false);
    }
private:
    SegmentNode *root;
    
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */