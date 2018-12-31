class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> cnt(26, 0);
        vector<bool> inSt(26, false);
        for (auto ch : s) {
            ++cnt[ch - 'a'];
        }
        for (auto ch : s) {
            if (!inSt[ch - 'a']) {
                while (!st.empty() && st.top() >= ch && cnt[st.top() - 'a'] > 0) {
                    inSt[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(ch);
                inSt[ch - 'a'] = true;
            }
            --cnt[ch - 'a'];
        }
        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};