class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        m = seats.size(), n = seats[0].size();
        vector<vector<int>> dp(m, vector<int>(1 << n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                if (isValid(seats, i, j)) {
                    if (i == 0) {
                        dp[i][j] = getCount(j);
                    } else {
                        for (int k = 0; k < (1 << n); ++k) {
                            if (isCompatible(k, j)) {
                                dp[i][j] = max(dp[i - 1][k], dp[i][j]);
                            }
                        }
                        dp[i][j] += getCount(j);
                    }
                }
            }
        }
        return *max_element(dp[m - 1].begin(), dp[m - 1].end());
    }
private:
    int m, n;
    bool isValid(vector<vector<char>>& seats, int x, int s) {
        int prev = 0;
        int t = s;
        while (t > 0) {
            int now = t % 2;
            if (prev == 1 && now == 1) {
                return false;
            }
            prev = now;
            t /= 2;
        }
        int i = 0;
        while (s > 0) {
            if (s % 2 == 1 && seats[x][i] != '.') {
                return false;
            }
            s /= 2;
            ++i;
        }
        return true;
    }
    bool isCompatible(int s, int t) {
        vector<int> sa, ta;
        for (int i = 0; i < n; ++i) {
            sa.push_back(s % 2);
            ta.push_back(t % 2);
            s /= 2;
            t /= 2;
        }
        for (int i = 0; i < n; ++i) {
            if (ta[i] == 1 && ((i > 0 && sa[i - 1] == 1) || (i < n - 1 && sa[i + 1] == 1))) {
                return false;
            }
        }
        return true;
    }
    int getCount(int s) {
        int cnt = 0;
        while (s > 0) {
            cnt += s % 2;
            s /= 2;
        }
        return cnt;
    }
};