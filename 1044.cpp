class SuffixRanker {
public:
    int index;
    int ranker[2];
    SuffixRanker(int index, int ranker0, int ranker1): index(index) {
        ranker[0] = ranker0, ranker[1] = ranker1;
    }
};

class Solution {
public:
    string longestDupSubstring(string S) {
        auto suffix = buildSuffix(S);
        auto rank = buildRank(suffix);
        auto lcp = buildLCP(S, suffix, rank);
        int index = max_element(lcp.begin(), lcp.end()) - lcp.begin();
        return S.substr(suffix[index], lcp[index]);
    }
private:
    vector<int> buildSuffix(string &s) {
        int n = s.length();
        vector<SuffixRanker> suffixRankers;
        for (int i = 0; i < n; ++i) {
            suffixRankers.emplace_back(i, s[i] - 'a', -1);
        }
        for (int i = 0; i < n - 1; ++i) {
            suffixRankers[i].ranker[1] = suffixRankers[i + 1].ranker[0];
        }
        sort(suffixRankers.begin(), suffixRankers.end(), cmp);
        for (int k = 2; k < n; k *= 2) {
            int prevRanker = suffixRankers[0].ranker[0], ranker = 0;
            suffixRankers[0].ranker[0] = ranker;
            vector<int> rank(n, 0);
            rank[suffixRankers[0].index] = 0;
            for (int i = 1; i < n; ++i) {
                if (suffixRankers[i].ranker[0] == prevRanker && suffixRankers[i].ranker[1] == suffixRankers[i - 1].ranker[1]) {
                    suffixRankers[i].ranker[0] = ranker;
                } else {
                    prevRanker = suffixRankers[i].ranker[0];
                    suffixRankers[i].ranker[0] = ++ranker;
                }
                rank[suffixRankers[i].index] = i;
            }
            for (int i = 0; i < n; ++i) {
                int nextRankerIndex = suffixRankers[i].index + k;
                suffixRankers[i].ranker[1] = nextRankerIndex < n ? suffixRankers[rank[nextRankerIndex]].ranker[0] : -1;
            }
            sort(suffixRankers.begin(), suffixRankers.end(), cmp);
        }
        vector<int> suffix;
        for (int i = 0; i < n; ++i) {
            suffix.push_back(suffixRankers[i].index);
        }
        return suffix;
    }
    
    vector<int> buildRank(vector<int> &suffix) {
        int n = suffix.size();
        vector<int> rank(n, 0);
        for (int i = 0; i < n; ++i) {
            rank[suffix[i]] = i;
        }
        return rank;
    }
    
    vector<int> buildLCP(string &s, vector<int> &suffix, vector<int> &rank) {
        int n = s.length();
        vector<int> lcp(n, 0);
        int l = 0;
        for (int i = 0; i < n; ++i) {
            if (rank[i] == n - 1) {
                l = 0;
                continue;
            }
            int j = suffix[rank[i] + 1];
            while (i + l < n && j + l < n && s[i + l] == s[j + l]) {
                ++l;
            }
            lcp[rank[i]] = l;
            if (l > 0) {
                --l;
            }
        }
        return lcp;
    }
    
    static bool cmp(const SuffixRanker &a, const SuffixRanker &b) {
        return a.ranker[0] < b.ranker[0] || a.ranker[0] == b.ranker[0] && a.ranker[1] < b.ranker[1];
    }
};
