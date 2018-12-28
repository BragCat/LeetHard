class Solution {
public:
    int countDigitOne(int n) {
        string strN = to_string(n);
        int len = strN.length();
        return count1WithPrefix(strN, "");
    }
private:
    int count1WithPrefix(const string &n, string p) {
        int oneCnt = 0;
        for_each(p.begin(), p.end(), [&oneCnt](char ch) mutable {oneCnt += ch == '1';});
        if (p.length() == n.length()) {
            return oneCnt;
        }

        int lenP = p.length(), ans = 0;
        if (p == n.substr(0, lenP)) {
            for (char ch = '0'; ch <= n[lenP]; ++ch) {
                ans += count1WithPrefix(n, p + ch);
            }
        } else {
            int m = n.length() - lenP;
            for (int i = 1; i <= m; ++i) {
                ans += i * combination(m, i) * pow(9, m - i);
                cout  << ans << endl;
            }
            ans += oneCnt * pow(10, m);
        }
        return ans;
    }
    int combination(int n, int k) {
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans *= i;
        }
        for (int i = 1; i <= k; ++i) {
            ans /= i;
        }
        for (int i = 1; i <= n - k; ++i) {
            ans /= i;
        }
        return ans;
    }
};