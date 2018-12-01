class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordNum = words.size();
        if (wordNum == 0) {
            return vector<int>{}; 
        } 
        int wordLen = words[0].size();
        vector<vector<int>> prevArrays;
        for (auto str : words) {
            vector<int> prev(wordLen, -1);
            int j = -1;
            for (int i = 1; i < wordLen; ++i) {
                while (j >= 0 && str[j + 1] != str[i]) {
                    j = prev[j];
                }
                if (str[j + 1] == str[i]) {
                    ++j; 
                }
                prev[i] = j;
            } 
            prevArrays.push_back(prev);
        }

        vector<int> wordIndexes(s.size(), -1);
        vector<int> cursors(wordNum, -1);
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < wordNum; ++j) {
                auto &cursor = cursors[j];
                auto &prev = prevArrays[j];
                auto &word = words[j];
                while (cursor >= 0 && word[cursor + 1] != s[i]) {
                    cursor = prev[cursor]; 
                } 
                if (word[cursor + 1] == s[i]) {
                    ++cursor; 
                }
                if (cursor == wordLen - 1) {
                    wordIndexes[i - wordLen + 1] = j; 
                    cursor = prev[cursor];
                }
            } 
        }

        vector<int> ans;
        unordered_map<string, int> wordCnt;
        for (auto &word : words) {
            if (wordCnt.find(word) == wordCnt.end()) {
                wordCnt[word] = 1; 
            } else {
                ++wordCnt[word]; 
            }
        }


        for (int i = 0; i < wordLen; ++i) {
            int l = i, r = i + wordLen * wordNum;
            if (r > s.size()) {
                break; 
            }
            int cnt = 0;
            unordered_map<string, int> newWordCnt;
            for (int j = l; j < r; j += wordLen) {
                if (wordIndexes[j] != -1) {
                    auto &word = words[wordIndexes[j]];
                    int a = ++newWordCnt[word];
                    int b = wordCnt[word];
                    if (a == b) {
                        cnt += b; 
                    } else if (a == b + 1) {
                        cnt -= b; 
                    }
                }
            }
            if (cnt == wordNum) {
                ans.push_back(l); 
            }
            while (r + wordLen - 1 < s.size()) {
                if (wordIndexes[l] != -1) {
                    auto &word = words[wordIndexes[l]];
                    int a = --newWordCnt[word];
                    int b = wordCnt[word];
                    if (a == b) {
                        cnt += b; 
                    } else if (a == b - 1) {
                        cnt -= b; 
                    }
                }
                if (wordIndexes[r] != -1) {
                    auto &word = words[wordIndexes[r]];
                    int a = ++newWordCnt[word];
                    int b = wordCnt[word];
                    if (a == b) {
                        cnt += b; 
                    } else if (a == b + 1) {
                        cnt -= b; 
                    }
                }
                l += wordLen, r += wordLen;
                if (cnt == wordNum) {
                    ans.push_back(l); 
                }
            }
        }

        return ans;
    }
};
