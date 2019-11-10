class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        vector<int> value(n);
        for (int i = 0; i < n; ++i) {
            string& w = words[i];
            for (char ch : w) {
                int l = ch - 'a';
                ++cnt[i][l];
                value[i] += score[l];
            }
        }
        vector<int> tot(26);
        for (char ch : letters) {
            int l = ch - 'a';
            ++tot[l];
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> now(26);
            int v = 0;
            bool valid = true;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    for (int k = 0; k < 26; ++k) {
                        now[k] += cnt[j][k];
                        if (now[k] > tot[k]) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) {
                        break;
                    }
                    v += value[j];
                }
            }
            if (valid) {
                ans = max(ans, v);
            }
        }
        return ans;
    }
};