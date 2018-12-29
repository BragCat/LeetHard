class Solution {
public:
    Solution(int N, vector<int> blacklist): N(N), blacklist(blacklist) {
        sort(this->blacklist.begin(), this->blacklist.end());
        n = N - blacklist.size();
        this->blacklist.push_back(N);
    }
    
    int pick() {
        int index = n * (static_cast<double>(rand())/ MAX_INT) + 1;
        int left = 0, right = blacklist.size() - 1;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (blacklist[mid] - mid >= index) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (ans == 0) {
            return index - 1;
        } else {
            return blacklist[ans - 1] + index - (blacklist[ans - 1] - (ans - 1));
        }
    }
private:
    const int MAX_INT = ~0u >> 1;
    const int MODULO = 1e9 + 7;
    vector<int> blacklist;
    int n, N;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */