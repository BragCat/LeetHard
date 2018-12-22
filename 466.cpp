class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_set<char> chars;
        for (auto &ch : s1) {
            chars.insert(ch);
        }
        for (auto &ch : s2) {
            if (chars.find(ch) == chars.end()) {
                return 0;
            }
        }
        
        int first = -1, ans = 0, cycleCnt = 0, j = 0;
        for (int i = 0; i < s1.size() * n1; ++i) {
            if (s2[j] == s1[i % s1.size()]) {
                ++j;
            }
            if (j == s2.size()) {
                ++ans;
                ++cycleCnt;
                if (first == -1) {
                    first = i;
                    cycleCnt = 0;
                } else {
                    if ((i - first) % s1.size() == 0) {
                        int cycleLen = i - first;
                        int remainLen = s1.size() * n1 - (i + 1);
                        ans += remainLen / cycleLen * cycleCnt;
                        i += remainLen / cycleLen * cycleLen;
                    }
                }
                j = 0;
            }
        }
        return ans / n2;
    }
};