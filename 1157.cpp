class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            v2ind[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for (auto it = v2ind.begin(); it != v2ind.end(); ++it) {
            auto& index = it->second;
            int l = 0, r = index.size() - 1;
            int ans = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (index[mid] <= right) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (ans != -1 && ans >= threshold - 1 && index[ans - threshold + 1] >= left) {
                return it->first;
            }
        }
        return -1;
    }
private:
    unordered_map<int, vector<int>> v2ind;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */