class Solution {
public:
    string crackSafe(int n, int k) {
        vector<string> all;
        getAllPWD(n, k, "", all);
        int allCnt = all.size();
        vector<vector<int>> edges(allCnt, vector<int>{});
        for (int i = 0; i < allCnt; ++i) {
            for (int j = 0; j < allCnt; ++j) {
                if (i != j) {
                    if (all[i].substr(1) == all[j].substr(0, n - 1)) {
                        edges[i].push_back(j);
                    }
                }
            }
        }
        string ans(all[0]);
        vector<bool> searched(allCnt, false);
        getAns(ans, 0, 1, all, searched, edges);
        return ans;
    }
private:
    void getAllPWD(int n, int k, string now, vector<string> &all) {
        if (now.length() == n) {
            all.push_back(now);
            return;
        }
        for (int i = 0; i < k; ++i) {
            getAllPWD(n, k, now + static_cast<char>(i + '0'), all);
        }
    }
    bool getAns(string &ans, int index, int cnt, vector<string> &all, vector<bool> &searched, vector<vector<int>> &edges) {
        if (cnt == all.size()) {
            return true;
        }
        string t = ans;
        ans = ans + ' ';
        searched[index] = true;
        for (int i = 0; i < edges[index].size(); ++i) {
            if (!searched[edges[index][i]]) {
                ans.back() = all[edges[index][i]].back();
                if (getAns(ans, edges[index][i], cnt + 1, all, searched, edges)) {
                    return true;
                } 
            }
        }
        searched[index] = false;
        ans = t;
        return false;
    }
};