class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.insert(stations.begin(), vector<int>{0, startFuel});
        stations.push_back(vector<int>{target, 0});
        int n = stations.size();
        vector<vector<int>> f(n, vector<int>(n, MIN_INT));
        f[0][0] = stations[0][1];
        for (int j = 1; j < n; ++j) {
            for (int i = 1; i < n; ++i) {
                for (int k = 0; k < i; ++k) {
                    if (f[k][j - 1] >= (stations[i][0] - stations[k][0])) {
                        f[i][j] = max(f[i][j], f[k][j - 1] - (stations[i][0] - stations[k][0]) + stations[i][1]);
                    }
                }
            }
            if (f[n - 1][j] >= 0) {
                return j - 1;
            }
        }
        return -1;
    }
private:
    const int MIN_INT = -static_cast<int>(~0u >> 1) - 1;
};