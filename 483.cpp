class Solution {
public:
    string smallestGoodBase(string n) {
        LL num = stoll(n);
        for (int i = 63; i > 1; --i) {
            LL left = 2, right = min(sqrt(num), pow(num + 1, 1.0 / (i - 1)));
            while (left <= right) {
                LL mid = left + (right - left) / 2;
                LL lv = 0;
                for (int j = 0; j < i; ++j) {
                    lv += power(mid, j);
                }
                if (lv == num) {
                    return to_string(mid);
                } else if (lv > num) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return to_string(num - 1);
    }
private:
    using LL = long long;
    LL power(LL b, int p) {
        LL ans = 1;
        for (int i = 0; i < p; ++i) {
            ans *= b;
        }
        return ans;
    } 
};
