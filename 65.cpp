class Solution {
public:
    bool isNumber(string s) {
        int pos = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                pos = i;
                break;
            }
        }
        s = s.substr(pos);
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                pos = i;
                break;
            }
        }
        s = s.substr(0, pos + 1);
        if (s.length() != 0 && (s[0] == '+' || s[0] == '-')) {
            s = s.substr(1);
        }
        int n = s.length();
        if (isInteger(s)) {
            return true;
        }
        auto ePos = s.find('e');
        if (ePos != string::npos) {
            string left = s.substr(0, ePos);
            string right = s.substr(ePos + 1);
            if (right.length() != 0 && (right[0] == '+' || right[0] == '-')) {
                right = right.substr(1);
            }
            auto dotPos = left.find('.');
            if (dotPos != string::npos) {
                return ((dotPos == 0 || isInteger(left.substr(0, dotPos))) &&
                        (dotPos == left.length() - 1 || isInteger(left.substr(dotPos + 1))) &&
                        (left.length() != 1) && isInteger(right));
            } else {
                return (isInteger(left) && isInteger(right));
            }
        }

        auto dotPos = s.find('.');
        if (dotPos != string::npos) {
            return ((isInteger(s.substr(0, dotPos)) || dotPos == 0) &&
                    (dotPos == n - 1 || isInteger(s.substr(dotPos + 1))) &&
                    (n != 1));
        }
        return false;
    }

private:
    bool isInteger(string s) {
        int n = s.length();
        if (n == 0) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        return true;
    }
};
