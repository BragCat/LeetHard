class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    ++height[j];
                }
            }
            vector<int> mq;
            vector<int> left(n, 0), right(n, n - 1);
            for (int j = 0; j < n; ++j) {
                while (!mq.empty() && height[mq.back()] >= height[j]) {
                    mq.pop_back();
                }
                if (!mq.empty()) {
                    left[j] = mq.back() + 1;
                }
                mq.push_back(j);
            }
            mq.clear();
            for (int j = n - 1; j >= 0; --j) {
                while (!mq.empty() && height[mq.back()] >= height[j]) {
                    mq.pop_back();
                }
                if (!mq.empty()) {
                    right[j] = mq.back() - 1;
                }
                mq.push_back(j);
            }
            for (int j = 0; j < n; ++j) {
                ans = max(ans, (right[j] - left[j] + 1) * height[j]);
            }
        }
        return ans;
    }
};