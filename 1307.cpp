class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        for (auto& w : words) {
            reverse(w.begin(), w.end());
        }
        reverse(result.begin(), result.end());
        used = vector<bool>(10, false);
        return search(words, result, 0, 0, 0);
    }
private:
    unordered_map<char, int> digit;
    vector<bool> used;
    bool search(vector<string>& words, string result, int wi, int di, int add) {
        if (wi == words.size()) {
            if (di < result.size()) {
                if (digit.find(result[di]) == digit.end()) {
                    if (used[add % 10]) {
                        return false;
                    }
                    digit[result[di]] = add % 10;
                    used[add % 10] = true;
                    bool ans = search(words, result, 0, di + 1, add / 10);
                    used[add % 10] = false;
                    digit.erase(result[di]);
                    return ans;
                } else if (digit[result[di]] != add % 10) {
                    return false;
                } else {
                    return search(words, result, 0, di + 1, add / 10);
                }
            } else {
                return add == 0;
            }
        }
        if (di >= words[wi].size()) {
            return search(words, result, wi + 1, di, add);
        }
        if (digit.find(words[wi][di]) != digit.end()) {
            if (di + 1 == words[wi].size() && digit[words[wi][di]] == 0) {
                return false;
            }
            return search(words, result, wi + 1, di, add + digit[words[wi][di]]);
        }
        for (int i = 0; i < 10; ++i) {
            if (!used[i]) {
                if (di + 1 == words[wi].size() && i == 0) {
                    continue;
                }
                digit[words[wi][di]] = i;
                used[i] = true;
                bool ans = search(words, result, wi + 1, di, add + i);
                if (ans) {
                    return true;
                }
                used[i] = false;
                digit.erase(words[wi][di]);
            } 
        }
        return false;
    }
};