class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> word2Index;
        for (int i = 0; i < words.size(); ++i) {
            word2Index[words[i]] = i;
        }
        vector<vector<int>> ans; 
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].length(); ++j) {
                if (isPalin(words[i].substr(words[i].length() - j))) {
                    string rev(words[i].substr(0, words[i].length() - j));
                    reverse(rev.begin(), rev.end());
                    auto it = word2Index.find(rev);
                    if (it != word2Index.end() && it->second != i) {
                        ans.push_back({i, it->second});
                    }
                }
                if (isPalin(words[i].substr(0, j))) {
                    string rev(words[i].substr(j));
                    reverse(rev.begin(), rev.end());
                    auto it = word2Index.find(rev);
                    if (it != word2Index.end() && it->second != i) {
                        ans.push_back({it->second, i});
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        return ans;
    }
private:
    bool isPalin(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l, --r;
        }
        return true;
    }
};