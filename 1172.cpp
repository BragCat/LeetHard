class DinnerPlates {
public:
    DinnerPlates(int capacity):capacity(capacity) {
    }
    
    void push(int val) {
        if (availStacks.empty()) {
            stackValues.push_back({});
            availStacks.insert(stackValues.size() - 1);
        }
        int index = *availStacks.begin();
        stackValues[index].push_back(val);
        if (stackValues[index].size() == capacity) {
            availStacks.erase(index);   
        } 
        if (stackValues[index].size() == 1) {
            nonEmptyStacks.insert(index);
        }
    }
    
    int pop() {
        if (nonEmptyStacks.empty()) {
            return -1;
        }
        int index = *nonEmptyStacks.rbegin();
        int ans = stackValues[index].back();
        stackValues[index].pop_back();
        if (stackValues[index].size() == 0) {
            nonEmptyStacks.erase(index);
        }
        if (stackValues[index].size() == capacity - 1) {
            availStacks.insert(index);
        }
        return ans;
    }
    
    int popAtStack(int index) {
        if (stackValues[index].empty()) {
            return -1;
        }
        int ans = stackValues[index].back();
        stackValues[index].pop_back();
        if (stackValues[index].size() == 0) {
            nonEmptyStacks.erase(index);
        }
        if (stackValues[index].size() == capacity - 1) {
            availStacks.insert(index);
        }
        return ans;
    }
private:
    int capacity;
    set<int> availStacks;
    set<int> nonEmptyStacks;
    vector<vector<int>> stackValues;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */