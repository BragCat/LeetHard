class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());
        int m = arr1.size(), n = arr2.size();
        vector<vector<int>> f(m, vector<int>(n + 1, MAX_INT));
        f[0][n] = 0;
        for (int i = 0; i < n; ++i) {
            f[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            if (arr1[i - 1] < arr1[i]) {
                f[i][n] = min(f[i][n], f[i - 1][n]);
            }
            for (int j = 0; j < n; ++j) {
                if (arr2[j] < arr1[i]) {
                    f[i][n] = min(f[i][n], f[i - 1][j]);
                }
                if (arr2[j] > arr1[i - 1] && f[i - 1][n] != MAX_INT) {
                    f[i][j] = min(f[i][j], f[i - 1][n] + 1);
                }
            }
            int minimum = MAX_INT;
            for (int j = 0; j < n; ++j) {
                f[i][j] = min(f[i][j], minimum);
                if (f[i - 1][j] != MAX_INT) {
                    minimum = min(minimum, f[i - 1][j] + 1);
                }
            }
        }
        int ans = *min_element(f[m - 1].begin(), f[m - 1].end());
        return ans != MAX_INT ? ans : -1;
    }
private:
    const int MAX_INT = ~0u >> 1;
};