class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        if (words.empty()) {
            return ans;
        }
        sort(words.begin(), words.end(), [](const string &a, const string &b) -> bool {return a.length() < b.length();});
        unordered_set<string> wordSet;
        for (int i = 0; i < words.size(); ++i) {
            if (canBeFormed(words[i], wordSet)) {
                ans.push_back(words[i]);
            }
            wordSet.insert(words[i]);
        }
        return ans;
    }
private:
    bool canBeFormed(const string &word, const unordered_set<string> &wordSet) {
        if (word.empty()) {
            return false;
        }
        int len = word.length();
        vector<bool> f(len + 1, false);
        f[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                string subWord = word.substr(j, i - j);
                if (!f[j]) {
                    continue;
                }

                if (wordSet.find(subWord) != wordSet.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[len];
    }
};