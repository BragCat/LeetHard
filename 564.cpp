class Solution {
public:
    string nearestPalindromic(string n) {
        long len = n.size(), num = stol(n);
        long ans = 0, minDiff = LONG_MAX;
        unordered_set<long> s;
        s.insert(pow(10, len) + 1);
        s.insert(pow(10, len - 1) - 1);
        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (long i = -1; i <= 1; ++i) {
            string pre = to_string(prefix + i);
            string str = pre + string(pre.rbegin() + (len & 1), pre.rend());
            s.insert(stol(str));
        }
        s.erase(num);
        for (auto x : s) {
            long diff = abs(x - num);
            if (diff < minDiff) {
                minDiff = diff;
                ans = x;
            } else if (diff == minDiff) {
                ans = min(ans, x);
            }
        }
        return to_string(ans);
    }
};
