class Solution {
public:
    int preimageSizeFZF(int K) {
        long long sup = 0;
        long long cnt = -1, n = 1;
        while (cnt < K) {
            n *= 5;
            long long b = n;
            cnt = 0;
            while (b > 0) {
                cnt += b / 5;
                b /= 5;
            }
        }
        sup = n * 5;
        long long l = getMaxNumberFromFive(sup, K - 1), r = getMaxNumberFromFive(sup, K);
        return r - l;
    }
private:
    int getMaxNumberFromFive(long long sup, int fiveNumber) {
        if (fiveNumber == -1) {
            return -1;
        }
        long long l = 0, r = sup;
        int ans = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            int fiveCnt = getFiveCount(mid);
            if (fiveCnt <= fiveNumber) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
    int getFiveCount(long long n) {
        long long base = 5, cnt = 0;
        while (base <= n) {
            cnt += n / base;
            base *= 5;
        }
        return cnt;
    }
};