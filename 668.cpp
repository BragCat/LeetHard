class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int le = getLECount(m, n, mid);
            int ls = getLECount(m, n, mid - 1);
            if (le < k) {
                l = mid + 1;
            } else if (ls >= k){
                r = mid - 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
private:
    int getLECount(int m, int n, int num) {
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            cnt += min(n, num / i);
        }
        return cnt;
    }
};