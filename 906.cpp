class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        return getSqrtNumber(0, "", L, R);
    }
private:
    const int MAX_LEN = 5;
    int getSqrtNumber(int i, string now, const string &L, const string &R) {
        if (i == R.length() / 4 + 1) {
            int ans = 0;
            string rev(now);
            reverse(rev.begin(), rev.end());
            string sqrt = removeZero(now + rev);
            if (validAndInRange(getSqr(sqrt), L, R)) {
                ++ans;
            }
            sqrt = removeZero(now + rev.substr(1));
            if (validAndInRange(getSqr(sqrt), L, R)) {
                ++ans;
            }
            return ans;
        }
        int ans = 0;
        for (char ch = '0'; ch <= '9'; ++ch) {
            ans += getSqrtNumber(i + 1, now + ch, L, R);
        }
        return ans;
    }
    string removeZero(string number) {
        int left = 0, right = number.length() - 1;
        while (number[left] == '0' && left <= right) {
            ++left, --right;
        }
        if (left > right) {
            return "0";
        }
        return number.substr(left, right - left + 1);
    }
    string getSqr(const string &s) {
        long long number = stoll(s);
        number = number * number;
        return to_string(number);
    }
    bool validAndInRange(const string &number, const string &L, const string &R) {
        int left = 0, right = number.size() - 1;
        while (left < right) {
            if (number[left] != number[right]) {
                return false;
            }
            ++left, --right;
        }
        if (number.length() > L.length() && number.length() < R.length()) {
            return true;
        }
        if (number.length() < L.length() || number.length() > R.length()) {
            return false;
        }
        if (number.length() == L.length()) {
            if (number.length() == R.length()) {
                return number >= L && number <= R;
            } else {
                return number >= L;
            }
        } else {
            return number <= R;
        }
    }
};