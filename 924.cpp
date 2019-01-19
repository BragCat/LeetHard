class Node {
public:
    int root, num, malNum;
    Node(): root(-1), num(1), malNum(0) {}
};
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        sort(initial.begin(), initial.end());
        vector<Node> f(n, Node());
        for (auto mal : initial) {
            f[mal].malNum = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j] == 1) {
                    unionSet(f, i, j);
                }
            }
        }
        int ans = -1;
        int rAns = -1;
        int nAns = 0;
        for (auto mal : initial) {
            int r = getRoot(f, mal);
            if (ans == -1 || (f[r].malNum == 1 && f[r].num > nAns)) {
                ans = mal;
                rAns = r;
                nAns = ((f[r].malNum == 1) ? f[r].num : 0);
            }
        }
        return ans;
    }
private:
    int getRoot(vector<Node> &f, int x) {
        if (f[x].root == -1) {
            return x;
        }
        return f[x].root = getRoot(f, f[x].root);
    }
    void unionSet(vector<Node> &f, int x, int y) {
        int rx = getRoot(f, x);
        int ry = getRoot(f, y);
        if (rx != ry) {
            if (f[rx].num >= f[ry].num) {
                f[ry].root = rx;
                f[rx].num += f[ry].num;
                f[rx].malNum += f[ry].malNum;
                f[ry].num = f[ry].malNum = 0;
            } else {
                f[rx].root = ry;
                f[ry].num += f[rx].num;
                f[ry].malNum += f[rx].malNum;
                f[rx].num = f[rx].malNum = 0;
            }
        }
    }
};