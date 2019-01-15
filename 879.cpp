class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = group.size();
        int sump = accumulate(profit.begin(), profit.end(), 0);
        vector<vector<int>> f(G + 1, vector<int>(sump + 1, 0)), g(G + 1, vector<int>(sump + 1, 0));
        f[0][0] = 1;
        int curSump = 0;
        for (int k = 0; k < n; ++k) {
            curSump += profit[k];
            if (k % 2 == 0) {
                doDP(f, g, G, curSump, group[k], profit[k]);
            } else {
                doDP(g, f, G, curSump, group[k], profit[k]);
            }
        }
        
        int ans = 0;
        if ((n - 1) % 2 == 0) {
            ans = getAns(g, G, P, sump);
        } else {
            ans = getAns(f, G, P, sump);
        }
        return ans;
    }
private:
    const int MODULO = 1e9 + 7;
    void doDP(vector<vector<int>> &f, vector<vector<int>> &g, int G, int maxp, int np, int pro) {
        for (int i = 0; i <= G; ++i) {
            for (int j = 0; j <= maxp; ++j) {
                g[i][j] = f[i][j];
                if (i >= np && j >= pro) {
                    g[i][j] = (g[i][j] + f[i - np][j - pro]) % MODULO;
                }
            }
        }
    }
    int getAns(vector<vector<int>> &f, int G, int P, int maxp) {
        int ans = 0;
        for (int i = 0; i <= G; ++i) {
            for (int j = P; j <= maxp; ++j) {
                ans = (ans + f[i][j]) % MODULO;
            }
        }
        return ans;
    }
}; 