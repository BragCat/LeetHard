class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n == 0) {
            return false;
        }
        vector<vector<bool>> f(n, vector<bool>(n, false));
        if (stones[0] != 0 || (n >= 2 && stones[1] != 1)) {
            return false;
        }
        f[1][0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (f[i][j]) {
                    for (int d = -1; d <= 1; ++d) {
                        int k = getIndex(stones, stones[i] + stones[i] - stones[j] + d);
                        if (k != -1) {
                            f[k][i] = true;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (f[n - 1][i]) {
                return true;
            }
        }
        return false;
    }
private:
    int getIndex(vector<int> &stones, int s) {
        int left = 0, right = stones.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (stones[mid] == s) {
                return mid;
            } else if (stones[mid] > s) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};