class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        A.insert(A.begin(), "");
        vector<vector<string>> delta(A.size(), vector<string>(A.size(), ""));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                delta[i][j] = getDelta(A[i], A[j]);
            }
        }
        
        vector<vector<string>> ans(1 << A.size(), vector<string>(A.size(), ""));
        getAns(delta, ans, 1, 0);
        return ans[1][0];
    }
private:
    const int MAX_INT = ~0u >> 1;
    string getDelta(const string &a, const string &b) {
        for (int i = 1; i < a.size(); ++i) {
            bool isSame = true;
            int pa = i, pb = 0;
            while (pa < a.size() && pb < b.size()) {
                if (a[pa] != b[pb]) {
                    isSame = false;
                    break;
                }
                ++pa, ++pb;
            }
            if (isSame) {
                return b.substr(pb);
            }
        }
        return b;
    }
    void getAns(vector<vector<string>> &delta, vector<vector<string>> &ans, int searched, int now) {
        if (ans[searched][now] != "") {
            return;
        }
        if (searched == ((1 << delta.size()) - 1)) {
            return;
        }

        for (int i = 0; i < delta.size(); ++i) {
            if ((searched & (1 << i)) == 0) {
                int nextSearched = searched | (1 << i);
                getAns(delta, ans, nextSearched, i);
                if (ans[searched][now] == "" || ans[nextSearched][i].length() + delta[now][i].length() < ans[searched][now].length()) {
                    ans[searched][now] = delta[now][i] + ans[nextSearched][i];
                }
            }
        }
    }
};