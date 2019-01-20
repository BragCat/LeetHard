class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        vector<string> ans;
        int leftCnt = 0, rightCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++leftCnt;
            } else if (s[i] == ')') {
                if (leftCnt > 0) {
                    --leftCnt;
                } else {
                    ++rightCnt;
                }
            }
        }
        getAnsDFS(0, 0, leftCnt, rightCnt, "", s, ans);
        sort(ans.begin(), ans.end());
        auto last = unique(ans.begin(), ans.end());
        ans.erase(last, ans.end());
        return ans;
    }
private:
    void getAnsDFS(int i, int left, int skipLeft, int skipRight, string now, string &s, vector<string> &ans) {
        if (i == s.length()) {
            if (skipLeft == 0 && skipRight == 0) {
                ans.push_back(now);
            }
            return;
        }
        
        if (s[i] == '(') {
            getAnsDFS(i + 1, left + 1, skipLeft, skipRight, now + s[i], s, ans);
            getAnsDFS(i + 1, left, skipLeft - 1, skipRight, now, s, ans);
        } else if (s[i] == ')') {
            if (left > 0) {
                getAnsDFS(i + 1, left - 1, skipLeft, skipRight, now + s[i], s, ans);
            } 
            if (skipRight > 0) {
                getAnsDFS(i + 1, left, skipLeft, skipRight - 1, now, s, ans);
            }
        } else {
            getAnsDFS(i + 1, left, skipLeft, skipRight, now + s[i], s, ans);
        }
    }
};