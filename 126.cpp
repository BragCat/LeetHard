class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) {
            return vector<vector<string>>{vector<string>{beginWord}};
        }

        int beginIndex = -1, endIndex = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == beginWord) {
                beginIndex = i; 
            } 
            if (wordList[i] == endWord) {
                endIndex = i; 
            }
        }       
       

        if (endIndex == -1) {
            return vector<vector<string>>{};
        }

        if (beginIndex == -1) {
            wordList.push_back(beginWord); 
            beginIndex = wordList.size() - 1;
        }

        preProcess(wordList);
        bfs(wordList, beginIndex, endIndex);
        vector<string> seq;
        dfs(wordList, seq, beginIndex, endIndex);
        for (auto &seq : ans) {
            reverse(seq.begin(), seq.end());
        }
        return ans;
    }

private:
    const int MAX_INT = ~0u >> 1;
    vector<vector<int>> preWord, nextList;
    vector<vector<string>> ans;

    void preProcess(vector<string> &wordList) {
        int n = wordList.size();
        nextList = vector<vector<int>>(n, vector<int>{});
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (hamming(wordList[i], wordList[j]) == 1) {
                    nextList[i].push_back(j);
                    nextList[j].push_back(i);
                } 
            }
        } 
    }

    void bfs(vector<string> &wordList, int beginIndex, int endIndex) {
        int n = wordList.size();
        vector<bool> searched(n, false);
        vector<int> step(n, MAX_INT);
        deque<int> q{beginIndex};
        searched[beginIndex] = true;
        step[beginIndex] = 0;
        preWord = vector<vector<int>>(n, vector<int>{});
        while (!q.empty()) {
            int i = q.front();
            q.pop_front();
            if (step[i] >= step[endIndex]) {
                break;
            }
            for (int j : nextList[i]) {
                if (!searched[j]) {
                    searched[j] = true;
                    q.push_back(j);
                    step[j] = step[i] + 1;
                    preWord[j].push_back(i);
                } else if (step[i] + 1 == step[j]) {
                    preWord[j].push_back(i);
                }
            }
        }
    } 

    void dfs(vector<string> &wordList, vector<string> &seq, int beginIndex, int index) {
        seq.push_back(wordList[index]);
        if (index == beginIndex) {
            ans.push_back(seq);
            seq.pop_back();
            return;
        }
        for (int preIndex : preWord[index]) {
            dfs(wordList, seq, beginIndex, preIndex);
        }
        seq.pop_back();
    }

    int hamming(string &a, string &b) {
        int l = a.size();
        int cnt = 0;
        for (int i = 0; i < l; ++i) {
            cnt += (a[i] != b[i]);
        } 
        return cnt;
    }
};
