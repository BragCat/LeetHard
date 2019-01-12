class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int cnt = target.length();
        int limit = 10 * cnt;
        while (ans.size() < limit) {
            bool hasNew = false;
            for (int i = 0; i <= target.length() - stamp.length(); ++i) {
                if (canCover(target.substr(i, stamp.length()), stamp)) {
                    ans.push_back(i);
                    hasNew = true;
                    for (int j = 0; j < stamp.length(); ++j) {
                        cnt -= (target[i + j] != '?');
                        target[i + j] = '?';
                    }
                }
            }
            if (!hasNew) {
                break;
            }
        }
        if (cnt == 0) {
            reverse(ans.begin(), ans.end());
        } else {
            ans.clear();
        }
        return ans;
    }
private:
    bool canCover(string s, string t) {
        int qCnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '?') {
                ++qCnt;
            } else if (s[i] != t[i]) {
                return false;
            }
        }
        return (qCnt != s.length());
    }
};