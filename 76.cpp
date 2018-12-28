class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCnt, target;
        for (int i = 0; i < t.length(); ++i) {
            ++target[t[i]];
        } 
        int targetCnt = target.size();
        int i = 0, j = 0, cnt = 0;
        int ansStart = 0, ansLen = MAX_INT;
        while (j < s.length()) {
            while (j < s.length() && cnt < targetCnt) {
                auto it = target.find(s[j]);
                if (it != target.end()) {
                    ++charCnt[s[j]];
                    if (charCnt[s[j]] == it->second) {
                        ++cnt;
                    }
                }
                ++j;
            }
            if (cnt == targetCnt) {
                while (i < j && cnt == targetCnt) {
                    auto it = target.find(s[i]);
                    if (it != target.end()) {
                        --charCnt[s[i]];
                        if (charCnt[s[i]] == it->second - 1) {
                            --cnt;
                        }
                    }
                    ++i;
                }
                if (ansLen > j - (i - 1)) {
                    ansStart = i - 1;
                    ansLen = j - (i - 1);
                }
            }
        }
        if (ansLen == MAX_INT) {
            return "";
        } else {
            return s.substr(ansStart, ansLen);
        }
    }
private:
    const int MAX_INT = ~0u >> 1;
};